// count Primes In Range 0 to n
void sieve(){ // O(nloglogn)
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = 0;

    for (ll i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = 0;
        }
    }

    for (int i = 0; i < (int)isPrime.size(); ++i)
        if(isPrime[i])
            primes.push_back(i);
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
bool isPrime2(ll n) {	// O(sqrt(n))
    for(ll i=2; i*i <= n; i += 1 + (i & 1)){
    	if(n%i == 0) return false;
    }
    return true;
}
