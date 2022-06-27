// count Primes In Range 0 to n
void sieve(){ // O(nloglogn)
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = 0;

    for (ll i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            //for (int j = i * 2; j <= n; j += i) 
            for (ll j = i * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }

    for (int i = 0; i < (int)isPrime.size(); ++i)
        if(isPrime[i])
            primes.push_back(i);
}

//smallest prime factor
void leastPrimeFactor(int n){
    vector<int> lPrime(n+1, 0);
    lPrime[1] = 1;

    for (int i = 2; i <= n; i++){
        if (!lPrime[i]){
            // marking the prime number as its own lpf
            lPrime[i] = i;
            for (int j = i*i; j <= n; j += i)
                if (!lPrime[j])
                    lPrime[j] = i;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << i << ": " << lPrime[i] << "\n";
}

bool isPrime(ll n) {	// O(sqrt(n))
    if(n == 2) return true;
    if(n < 2 || n % 2 == 0) return false;
  
    for(ll i=3; i*i <= n; i+=2){
    	if(n%i == 0)
    		return false;
    }
    return true;
}
