#include <iostream>

using namespace std;

// Constant values to be passed to `findPlace`, i.e. fancy syntax
// sugar. Macros would work here too, but they're too much for this
// problem.
const int ONES = 0;
const int TENS = 1;
const int HUNDREDS = 2;

// divMod-style algorithm that dissects an integer `q` into its ones,
// tens, hundreds, and thousands places. Use the constants above to
// make it clear what we're obtaining.
int findPlace(int q, int s) {
  int r;

  r = q % 10;
  q = q / 10;

  for (int i = 0; i < s; i++) {
    r = q % 10;
    q = q / 10;
  }

  return r;
}

// User input, can also be taken from `cin`.
const int INPUT[] = {
  51,
  1282,
  2236,
  229,
  120,
  17,
};

const int INPUT_LENGTH = 6;

void getSum(string name, int stop) {
  int i;
  int output = 0;

  cout << "Sum of all " << name << ":";

  for (i = 0; i < INPUT_LENGTH; i++) {
    int place = findPlace(INPUT[i], stop);
    output += place;

    cout << " " << place;

    if (i + 1 != INPUT_LENGTH) {
      cout << " +";
    }

  };

  cout << " = " << output << endl;
}

// Contributed by Sons Justin Paraiso Garcia
int main() {
  getSum("Ones", ONES);
  getSum("Tens", TENS);
  getSum("Hundreds", HUNDREDS);
  return 0;
}