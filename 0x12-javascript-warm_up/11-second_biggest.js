#!/usr/bin/node

// Extract command-line arguments and convert to integers
let args = process.argv.slice(2).map((x) => {
    return parseInt(x);
});

// If there are less than two arguments, output 0
if (args.length <= 1) {
    console.log(0);
} else {
    // Sort the arguments in descending order and output the second largest
    console.log(args.sort((a, b) => {
	return b - a;
    })[1]);
}
