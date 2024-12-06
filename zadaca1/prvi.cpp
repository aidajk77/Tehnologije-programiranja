#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

enum class TretmanNegativnih {
  IgnorirajZnak,
  Odbaci,
  TretirajKao0,
  PrijaviGresku
};

int BrojKvadrata(int n) {
  if (n < 0) {
    throw domain_error("Broj mora biti nenegativan");
  }
  if (n == 0)
    return 0;
  for (int i = 0; i * i <= n; i++) {
    for (int j = i; j * j <= n; j++) {
      for (int k = j; k * k <= n; k++) {
        for (int l = k; l * l <= n; l++) {
          if (i * i + j * j + k * k + l * l == n) {
            if (i == 0 && j == 0 && k == 0)
              return 1;
            else if (i == 0 && j == 0)
              return 2;
            else if (i == 0)
              return 3;
            else
              return 4;
          }
        }
      }
    }
  }
  return 0;
}
array<vector<int>, 5> RazvrstajPoBrojuKvadrata(vector<int> v,
                                               TretmanNegativnih t) {
  array<vector<int>, 5> niz{};
  for (int i = 0; i < v.size(); i++) {
    int temp = v[i];
    if (temp < 0) {
      if (t == TretmanNegativnih::IgnorirajZnak) {
        temp = -temp;
        niz[BrojKvadrata(temp)].push_back(-temp);
      }
      if (t == TretmanNegativnih::Odbaci) {
        continue;
      }
      if (t == TretmanNegativnih::TretirajKao0) {
        niz[0].push_back(temp);
      }
      if (t == TretmanNegativnih::PrijaviGresku) {
        throw domain_error("Nije predvidjeno razvrstavanje negativnih brojeva");
      }
      continue;
    }
    niz[BrojKvadrata(temp)].push_back(temp);
  }
  return niz;
}

int main() {
  TretmanNegativnih t = TretmanNegativnih::PrijaviGresku;
  int a;
  vector<int> v;
  cout << "Unesite brojeve (bilo koji ne-broj oznacava kraj):" << endl;
  while (true) {
    cin >> a;
    if (a < 0) {
      cout << "Nije podrzano razvrstavanje negativnih brojeva!" << endl;
      return 0;
    }
    if (!cin)
      break;
    else
      v.push_back(a);
  }
  try {
    auto niz = RazvrstajPoBrojuKvadrata(v, t);
    cout << "Rezultati razvrstavanja po broju kvadrata: " << endl;
    for (int i = 0; i < niz.size(); i++) {
      if (niz.at(i).size() == 0)
        continue;
      cout << i << ": ";
      for (int j = 0; j < niz.at(i).size(); j++) {
        cout << niz.at(i).at(j) << " ";
      }
      cout << endl;
    }
  } catch (domain_error e) {
    cout << e.what() << endl;
  }

  return 0;
}