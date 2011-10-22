/**
 *
 *       @file  Prime.h
 *
 *      @brief  Prime number generator class
 *
 *    @version  1.0
 *       @date  10/19/2011 18:54:33
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef PRIME_H__
#define PRIME_H__
#include <cmath>
#include <vector>
using namespace std;
#include <System/AtkinSieve.h>
#include <System/EratostheneSieve.h>

class Prime {
public:
    /**
     * @brief Enum of the different Sieve types to generate primes
     */
    enum SieveType {
        /** Eratosthene sieve **/
        Eratosthene,
        /** Atkin Sieve **/
        Atkin
    };

    /**
     * @brief Constructor of the prime class
     * @param limit the max length of the prime you need
     * @param type the SieveType to use default Eratosthene
     * @see SieveType
     */
    Prime(unsigned long limit, Prime::SieveType type = Eratosthene);

    /**
     * @brief Generates the primes using the choosen sieve
     * @return 0 is success, -1 otherwise
     */
    int genPrimes();

    /**
     * @brief returns the biggest prime generated
     * @return a long containing the prime
     */
    long getBiggestPrime();

    /**
     * @brief puts all the primes generated in a vector
     * @return the vector containing these primes or an empy vector if an error occured
     */
    vector<long> getPrimes();

    /**
     * @brief Get the number of primes generated
     * @return the number of primes generated
     */
    long getNumberOfPrimes();

    /**
     * @brief checks if the number is a prime or not
     * @param num the number to check
     * @return true if prime number, false otherwise
     */
    static bool isPrime(long num);

private:
    PrimeSieve *m_sieve;
    unsigned long m_limit;
    SieveType m_type;

};

#endif
