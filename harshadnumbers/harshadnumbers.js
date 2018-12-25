const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

harshad = (n) => {
  digits = String(n).split('').map(d => parseInt(d));
  sd = digits.reduce((a, b) => a + b, 0);
  return n % sd === 0;
}

rl.on('line', (line) => {
  n = parseInt(line);
  while (!harshad(n)) {
    n++;
  }
  console.log(n);
});
