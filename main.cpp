#include <bits/stdc++.h>
using namespace std;

const int MAX_PRIME_SUM = 16 + 16;
bool primes[MAX_PRIME_SUM] = { false, false, true, true, false, true, false, true, false, false,
                               false, true, false, true, false, false, false, true, false, true,
                               false, false, false, true, false, false, false, false, false, true, false, true };
const int MAX_RING_SIZE = 16 + 1;
int prime_ring_idx, input;
int prime_ring[MAX_RING_SIZE];
bool number_taken[MAX_RING_SIZE];

void print_prime_ring();
void gen_prime_ring();

int main() {
    int caseNum = 1;

    prime_ring[1] = 1;
    for (auto && i : number_taken) { i = false; }

    number_taken[1] = true;

    while (std::cin >> input && input != 0)
    {
        if (caseNum != 1) { cout << endl; }
        std::cout << "Case " << caseNum << ":" << std::endl;
        ++caseNum;

        prime_ring_idx = 1;
        gen_prime_ring();
    }

    return 0;
}

void gen_prime_ring()
{
    if (prime_ring_idx >= input ) { print_prime_ring(); return; }

    for (int i = 2; i <= input; ++i )
    {
        if ( !number_taken[i] && primes[i + prime_ring[prime_ring_idx]] ) {
            if (prime_ring_idx == input - 1 && !primes[i + prime_ring[1]] ) { continue; }

            number_taken[i] = true;
            prime_ring[++prime_ring_idx] = i;

            gen_prime_ring();

            number_taken[i] = false;
            prime_ring[prime_ring_idx--] = 0;
        }
    }
}

void print_prime_ring()
{
    std::cout << prime_ring[1];
    for (int i = 2; i <= input; ++i ) { std::cout << " " << prime_ring[i]; }
    std::cout << std::endl;
}
