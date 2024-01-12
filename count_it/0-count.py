#!/usr/bin/python3
import praw

def count_words(subreddit, word_list, after=None, counts=None):
    if counts is None:
        counts = {}

    reddit = praw.Reddit(client_id='YOUR_CLIENT_ID',
                         client_secret='YOUR_CLIENT_SECRET',
                         user_agent='YOUR_USER_AGENT')

    try:
        subreddit_obj = reddit.subreddit(subreddit)
    except:
       
        return

    hot_posts = subreddit_obj.hot(limit=100, params={'after': after})

    for post in hot_posts:
        title = post.title.lower()

        for word in word_list:
            keyword = word.lower()

            
            if f' {keyword} ' in f' {title} ':
                counts[keyword] = counts.get(keyword, 0) + title.count(f' {keyword} ')

    next_page = hot_posts.params.get('after')
    if next_page:
        count_words(subreddit, word_list, after=next_page, counts=counts)
    else:
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))

        for keyword, count in sorted_counts:
            print(f"{keyword}: {count}")

if __name__ == '__main__':
    import sys

    if len(sys.argv) < 2:
        print("Usage: {} <subreddit>".format(sys.argv[0]))
        print("Ex: {} programming".format(sys.argv[0]))
    else:
        count_words(sys.argv[1], [x for x in sys.argv[2:]])
