#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.log('Please provide a movie ID as the first argument.');
} else {
  // Use the movie ID to fetch movie details
  const url = `https://swapi.dev/api/films/${movieId}/`;

  request(url, (error, response, body) => {
    if (error) {
      console.error('Error fetching data:', error);
    } else {
      // Parse the JSON response
      const film = JSON.parse(body);
      
      // Access the characters list for the current film
      const characters = film.characters;

      // Display characters in order
      characters.forEach(characterUrl => {
        // Fetch individual character details
        request(characterUrl, (error, response, body) => {
          if (error) {
            console.error('Error fetching character data:', error);
          } else {
            // Parse the JSON response for the character
            const character = JSON.parse(body);
            console.log(character.name);
          }
        });
      });
    }
  });
}
