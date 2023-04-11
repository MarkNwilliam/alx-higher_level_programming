#!/usr/bin/node
// Use strict mode to enforce better coding practices
'use strict';

const numArgs = process.argv.length - 2;

if (numArgs === 0) {
  console.log('No argument');
} else if (numArgs === 1) {
  console.log('Argument found');
} else {
  console.log('Arguments found');
}
