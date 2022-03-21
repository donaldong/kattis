const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

lc = 0;
D = null;

parseLine = line => {
  return line.split(' ').map(s => parseInt(s));
};

rl.on('line', line => {
  if (lc == 0) {
  } else if (lc == 1) {
    D = parseLine(line);
  } else {
    q = parseLine(line);
    if (q[0] == 1) {
      D[q[1] - 1] = q[2]
    } else {
      console.log(Math.abs(
        D[q[1] - 1] - D[q[2] - 1]
      ));
    }
  }
  lc++;
});
