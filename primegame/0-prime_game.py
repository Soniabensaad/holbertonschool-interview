#!/usr/bin/python3
"""
Defines function that determines the winner after a certain number of rounds
of playing the Prime Game
"""


def isWinner(x, nums):
    """
    The Prime Game,
    starting from the number 1 up to and including n,
    involves players taking turns selecting prime numbers
    and eliminating them along with their multiples from the set.
    The game concludes after a set number of rounds,
    determining the winner. Maria and Ben engage in this game,
    with Maria taking the first turn always.

    parameters:
        x [int]:
            the number of rounds
        nums [list of ints]:
            list of all ns for each round

    returns:
        the name of the player that won the most rounds,
        if both players play optimally,
        or None, if the winner cannot be determined
    """
    Maria = 0
    Ben = 0
    if (x < 1 or x != len(nums)):
        return None
    for n in nums:
        winner = primeGame(n)
        if winner == 1:
            Maria += 1
        elif winner == 2:
            Ben += 1
    if Maria == Ben:
        return None
    elif Maria > Ben:
        return "Maria"
    return "Ben"


def primeGame(n):
    """
    Determines the winner of a single round of the Prime Game

    parameters:
        n [int]:
            the maximum number of the set of consecutive ints
                from 1 up to and including n

    returns:
        1 if the first player wins the game
        2 if the second player wins the game
    """
    if (n < 1):
        return None
    if (n == 1):
        return (2)
    numbers = list(range(n + 1))
    player = 1
    prime = 2
    primes_used = []
    for num in numbers:
        if (num % prime == 0):
            numbers.remove(num)
    primes_used.append(prime)
    prime = 3
    while (numbers != [1]):
        if (player == 1):
            player = 2
        else:
            player = 1
        for num in numbers:
            if (num % prime == 0):
                numbers.remove(num)
        primes_used.append(prime)
        prime += 2
        flag = 1
        while (flag):
            for num in primes_used:
                if (prime % num == 0):
                    prime += 2
                    break
            else:
                flag = 0
    if (player == 1):
        return 1
    return 2
