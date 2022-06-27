/* Generador de casos de prueba, se genero usando tcframe */
#include<bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;
#define pb push_back

int prpw[108] = { 4, 8, 9, 16, 25, 27, 32, 49, 64, 81, 121, 125, 128, 169, 243, 256, 289, 343, 361, 512, 529, 625, 729, 841, 961, 1024, 1331, 1369, 1681, 1849, 2048, 2187, 2197, 2209, 2401, 2809, 3125, 3481, 3721, 4096, 4489, 4913, 5041, 5329, 6241, 6561, 6859, 6889, 7921, 8192, 9409, 10201, 10609, 11449, 11881, 12167, 12769, 14641, 15625, 16129, 16384, 16807, 17161, 18769, 19321, 19683, 22201, 22801, 24389, 24649, 26569, 27889, 28561, 29791, 29929, 32041, 32761, 32768, 36481, 37249, 38809, 39601, 44521, 49729, 50653, 51529, 52441, 54289, 57121, 58081, 59049, 63001, 65536, 66049, 68921, 69169, 72361, 73441, 76729, 78125, 78961, 79507, 80089, 83521, 85849, 94249, 96721, 97969 };

class ProblemSpec : public BaseProblemSpec {
    protected:
        int N;
        vector<long long> A;
        vector<long long> ans;

        void InputFormat(){
            LINE(N);
            LINES(A) % SIZE(N);
        }

        void OutputFormat(){
            LINES(ans) % SIZE(N);
        }

        void GradingConfig(){
            TimeLimit(6);
            MemoryLimit(512);
        }

        void Constraints(){
            CONS( N <= 1000000 );
            CONS( N >= 1 );
            CONS( eachElementBetween(A,1,4000000) );
        }

        void Subtask1(){
            Points(5);

            CONS( N <= 40 );
            CONS( N >= 1 );
            CONS( eachElementBetween(A,1,40) );
        }

        void Subtask2(){
            Points(20);

            CONS( N <= 100 );
            CONS( N >= 1 );
            CONS( eachElementBetween(A,1,100000) );
            CONS( SmallestPrimeGreaterThan(A,100) );
        }

        void Subtask3(){
            Points(20);

            CONS( N <= 10000 );
            CONS( N >= 1 );
            CONS( eachElementBetween(A,1,100000) );
            CONS( PrimePower(A) );
        }

        void Subtask4(){
            Points(25);

            CONS( N <= 100000 );
            CONS( N >= 1 );
            CONS( eachElementBetween(A,1,100000) );
        }

        void Subtask5(){
            Points(30);

            CONS( N <= 1000000 );
            CONS( N >= 1 );
            CONS( eachElementBetween(A,1,4000000) );
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

        bool SmallestPrimeGreaterThan( const vector <long long>& v, long long lim){
            for( auto i : v )
                for(int j=2; j*j<=i; j++)
                    if( i % j == 0 && j < lim )
                        return false;
            return true;
        }

        bool PrimePower(const vector <long long>& v){
            for( auto i : v ){
                int tmp = i;
                int c = 0;
                for(int j=2; j*j<=tmp; j++)
                    if( tmp % j == 0 ){
                        c ++;
                        while( tmp % j == 0 ) tmp /= j;
                    }
                c += ( tmp > 1 );
                if( c >= 2 ) return false;
            }
            return true;
        }
    };

class TestSpec : public BaseTestSpec<ProblemSpec> {
    protected:
        void BeforeTestCase(){
            A.clear();
        }

        void TestGroup1(){

            Subtasks({1,4,5});

            CASE(N=40,Assign(40,A,1,40));
        }

        void TestGroup2(){

            Subtasks({2,4,5});

            CASE(N=100,Custom(A,10,0,90));
            CASE(N=100,Custom(A,10,90,0));
            CASE(N=100,Custom(A,100,0,0));
            CASE(N=100,Custom(A,50,40,10));
        }

        void TestGroup3(){

            Subtasks({3,4,5});

            CASE(N=10000,PandPW(10000,A));
        }

        void TestGroup4(){

            Subtasks({4,5});

            CASE(N=100000,Assign(100000,A,1,100000));
            CASE(N=100000,AllEqual(100000,A,98280));

        }

        void TestGroup5(){

            Subtasks({5});

            CASE(N=1000000,Full(1000000,A,4000000));
            CASE(N=1000000,Worst(1000000,A,4000000));
            CASE(N=1000000,AllEqual(1000000,A,1965600));

        }


    private:
        void Assign(int limit, vector<long long>& w, long long minW, long long maxW) {
            for (int i = minW; i <= maxW; i++) {
                if( w.size() == limit ) break;
                w.push_back(i);
            }
        }
        void AllEqual(int limit, vector<long long>& w, int W) {
            for (int i = 0; i < limit; i++) {
                w.push_back(W);
            }
        }
        void PandPW(int limit,vector<long long>& w){
            for(int i=2; i<=100000; i++){
                bool isp = 1;
                for(int j=2; j*j<=i; j++)
                    if( i % j == 0 )
                        isp = 0;
                if( isp )
                    w.pb(i);
            }
            int x = 0;
            while( w.size() < limit ){
                w.pb(prpw[x]);
                x = ( x + 1 ) % 108;
            }
        }
        void Custom(vector<long long>& w,int t1,int t2,int t3){
            vector<int> v1;
            for(int i=100; i*i<100000; i++){
                bool isp = 1;
                for(int j=2; j*j<=i; j++)
                    if( i % j == 0 )
                        isp = 0;
                if( isp )
                    v1.pb(i);
            }
            vector<int> v2;
            for(int i=100; i<=100000; i++){
                bool isp = 1;
                for(int j=2; j*j<=i; j++)
                    if( i % j == 0 )
                        isp = 0;
                if( isp )
                    v2.pb(i);
            }
            for(int i=0; i<t1; i++){
                int x = rnd.nextInt(0,(int)v1.size()-1);
                int y = rnd.nextInt(0,(int)v1.size()-1);
                w.pb({v1[x]*v1[y]});
            }
            for(int i=0; i<t2; i++){
                int x = rnd.nextInt(0,(int)v1.size()-1);
                w.pb({v1[x]*v1[x]});
            }
            for(int i=0; i<t3; i++){
                int x = rnd.nextInt(0,(int)v2.size()-1);
                w.pb({v2[x]});
            }
        }
        void Full(int sz, vector<long long> &w,int mx){
            int cut = sz / 10 * 2;
            for(int i=1; i<=cut; i++){
                if( w.size() >= sz ) break;
                w.pb(i);
            }
            for(int i=1; i<=cut; i++){
                if( w.size() >= sz ) break;
                w.pb(mx-i+1);
            }
            while( w.size() < sz ){
                w.pb(rnd.nextInt(cut+1,mx-cut));
            }
        }
        void Worst(int sz, vector<long long> &w,int mx){
            vector<int> div(mx+1);
            for(int i=1; i<=mx; i++)
                for(int j=i; j<=mx; j+=i)
                    div[j] ++;
            vector<pair<int,int>> vx;
            for(int i=1; i<=mx; i++){
                vx.pb({div[i],i});
            }
            sort(vx.begin(),vx.end());
            while( w.size() < sz ){
                w.pb(vx.back().second);
                vx.pop_back();
            }
        }
    };

