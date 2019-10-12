#include <bits/stdc++.h>
using namespace std;

const int MAX_PRIME_SUM = 16 + 16;
bool primes[MAX_PRIME_SUM];

void gen_primes();

const int MAX = 17;
int prime_ring_idx, n;
int prime_ring[MAX];
bool number_taken[MAX];

void print_prime_ring();

void gen_prime_ring();

int main()
{
    int caseNum = 1;
    gen_primes();
    prime_ring[1] = 1;
    for (auto && i : number_taken) { i = false; }

    number_taken[1] = true;

    while ( std::cin >> n && n != 0)
    {
        if (caseNum != 1) { cout << endl; }
        std::cout << "Case " << caseNum << ":" << std::endl;
        ++caseNum;

        prime_ring_idx = 1;
        gen_prime_ring();
    }

    return 0;
}

void print_prime_ring()
{
    std::cout << prime_ring[1];
    for ( int i = 2; i <= n; ++i ) { std::cout << " " << prime_ring[i]; }
    std::cout << std::endl;
}

void gen_prime_ring()
{
    if ( prime_ring_idx >= n ) { print_prime_ring(); return; }

    for ( int i = 2; i <= n; ++i )
    {
        if ( !number_taken[i] && primes[i + prime_ring[prime_ring_idx]] )
        {
            if ( prime_ring_idx == n - 1 && !primes[i + prime_ring[1]] ) { continue; }

            number_taken[i] = true;
            prime_ring[++prime_ring_idx] = i;

            gen_prime_ring();

            number_taken[i] = false;
            prime_ring[prime_ring_idx--] = 0;
        }
    }
}

void gen_primes()
{
    std::fill(primes, primes + MAX_PRIME_SUM + 1, true);

    primes[0] = primes[1] = false;
    for (int i = 4; i < MAX_PRIME_SUM; i += 2 ) { primes[i] = false; }

    for (int p = 3; p < MAX_PRIME_SUM; p += 2 )
    {
        if ( !primes[p] ) { continue; }
        for (int i = p * p; i < MAX_PRIME_SUM; i += 2 * p ) { primes[i] = false; }
    }
}

