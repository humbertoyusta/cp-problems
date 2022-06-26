    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
#include <tcframe/spec.hpp>
#define ll long long
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()

using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
    protected:
        int N;
        vector<long long> A;
        vector<long long> ANS;

        void InputFormat(){
            LINE(N);
            LINES(A) % SIZE(N);
        }

        void OutputFormat(){
            LINES(ANS) % SIZE(N);
        }

        void GradingConfig(){
            TimeLimit(6);
            MemoryLimit(1024);
        }

        void Constraints(){
            CONS( N <= 100 );
            CONS( N >= 1 );
            CONS( eachElementBetween(A,1,1000000000ll*1000000000ll) );
        }

        void Subtask1(){
            Points(8);
            CONS( eachElementBetween(A,1,100) );
        }

        void Subtask2(){
            Points(12);
            CONS( eachElementBetween(A,1,3000) );
        }

        void Subtask3(){
            Points(15);
            CONS( N <= 10 );
            CONS( eachElementBetween(A,1,15000) );
        }

        void Subtask4(){
            Points(25);
            CONS( eachElementBetween(A,1,200000) );
        }

        void Subtask5(){
            Points(20);
            CONS( eachElementBetween(A,1,200000ll*200000ll) );
        }

        void Subtask6(){
            Points(20);
        }

    private:
        bool eachElementBetween(const vector<long long>& v, long long lo, long long hi) {
            for (long long x : v) {
                if (x < lo || x > hi) {
                    return false;
                }
            }
            return true;
        }
    };

class TestSpec : public BaseTestSpec<ProblemSpec> {
    protected:
        void BeforeTestCase(){
            A.clear();
            ANS.clear();
        }

        void TestGroup1(){

            Subtasks({1,2,3,4,5,6});

            all_tests(1,100);
        }

        void TestGroup2(){

            Subtasks({2,4,5,6});

            all_tests(1,3000);
        }

        void TestGroup3(){

            Subtasks({3,4,5,6});

            CASE(N=10,randomAssign(10,A,(int)sqrt(15000)-1));
            CASE(N=10,randomAssign(10,A,(int)sqrt(15000)-1));
            CASE(N=10,randomAssign(10,A,(int)sqrt(15000)-1));
            CASE(N=10,randomAssign(10,A,(int)sqrt(15000)-1));
            CASE(N=10,randomAssign(10,A,(int)sqrt(15000)-1));
        }

        void TestGroup4(){

            Subtasks({4,5,6});

            all_tests(12001,200000);
        }

        void TestGroup5(){

            Subtasks({5,6});

            CASE(N=100,randomAssign(100,A,200000));
            CASE(N=100,randomAssign(100,A,200000));
            CASE(100,randomAssign(100,A,200000));
        }

        void TestGroup6(){

            Subtasks({6});

            CASE(100,randomAssign(100,A,1000000000));
            CASE(100,randomAssign(100,A,1000000000));
            CASE(100,randomAssign(100,A,1000000000));
        }

    private:
        void all_tests(int lower_limit,int limit){
            vector<ll> v;
            for(ll i=1; i*i<=limit; i++){
                if( i * i >= lower_limit )
                    v.pb(i*i);
            }
            reverse(all(v));
            while( !v.empty() ){
                ll x = min( 100ll , (ll)v.size() );
                vector<ll> w;
                while( w.size() < x ){
                    w.pb(v.back());
                    v.pop_back();
                }
                CASE(N=x,A=w);
            }
        }

        bool isprime(int x){
            for(int i=2; i*i<=x; i++)
                if( x % i == 0 )
                    return false;
            return true;
        }

        void randomAssign(int m, vector<long long>& w,int limit) {

            ll x = 1;
            int cnt = 1;
            while( true ){
                ll y = x;
                cnt ++;
                y = y * cnt / __gcd(y,(ll)cnt);
                if( y > limit ) break;
                    else x = y;
            }
            w.pb(x*x);

            x = limit;
            while( !isprime(x) ) x--;
            w.pb(x*x);

            while( w.size() < m ){
                ll x = rnd.nextInt(1,limit);
                w.pb(x*x);
            }
        }

    };
