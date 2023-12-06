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
      const charactersPromises = film.characters.map(characterUrl => {
        // Return a promise for each character's details
        return new Promise((resolve, reject) => {
          request(characterUrl, (error, response, body) => {
            if (error) {
              reject(`Error fetching character data: ${error}`);
            } else {
              // Parse the JSON response for the character
              const character = JSON.parse(body);
              resolve(character.name);
            }
          });
        });
      });

      // Wait for all promises to resolve
      Promise.all(charactersPromises)
        .then(characterNames => {
          // Display characters in order
          characterNames.forEach(characterName => {
            console.log(characterName);
          });
        })
        .catch(error => {
          console.error('Error:', error);
        });
    }
  });
}
