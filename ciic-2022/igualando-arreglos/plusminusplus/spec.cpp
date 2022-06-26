/* Generador de casos de prueba, se genero usando tcframe */
#include<bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;
#define pb push_back


class ProblemSpec : public BaseProblemSpec {
    protected:
        int N, Q;
        vector<int> A, B, L, R, X;
        vector<string> ans;
        vector<long long> F;

        void InputFormat(){
            LINE(N, Q);
            LINE(A % SIZE(N));
            LINE(B % SIZE(N));
            LINES(L, R, X) % SIZE(Q);
        }

        void OutputFormat(){
            RAW_LINES(ans) % SIZE(Q+1);
        }

        void GradingConfig(){
            TimeLimit(2);
            MemoryLimit(256);
        }

        void Constraints(){
            CONS( N <= 200000 );
            CONS( N >= 3 );
            CONS( eachElementBetween(A,1,1000000) );
            CONS( eachElementBetween(B,1,1000000) );
            CONS( Q <= 200000 );
            CONS( eachElementBetween(L,1,N) );
            CONS( eachElementBetween(R,1,N) );
            CONS( eachElementBetween(X,-1000000,1000000) );
            CONS( alwaysSmaller(L,R) );
        }

        void Subtask1(){
            Points(10);

            CONS( N <= 100 );
            CONS( N >= 3 );
            CONS( eachElementBetween(A,1,100) );
            CONS( eachElementBetween(B,1,100) );
            CONS( Q == 0 );
        }

        void Subtask2(){
            Points(20);

            CONS( N <= 200000 );
            CONS( N >= 3 );
            CONS( eachElementBetween(A,1,1000000) );
            CONS( eachElementBetween(B,1,1000000) );
            CONS( Q == 0 );
        }

        void Subtask3(){
            Points(40);

            CONS( N <= 200000 );
            CONS( N >= 3 );
            CONS( eachElementBetween(A,1,1000000) );
            CONS( eachElementBetween(B,1,1000000) );
            CONS( Q <= 200000 );
            CONS( eachElementBetween(L,1,N) );
            CONS( eachElementBetween(R,1,N) );
            CONS( eachElementBetween(X,-1000000,1000000) );
            CONS( alwaysEqual(L,R) );
        }

        void Subtask4(){
            Points(30);

            CONS( N <= 200000 );
            CONS( N >= 3 );
            CONS( eachElementBetween(A,1,1000000) );
            CONS( eachElementBetween(B,1,1000000) );
            CONS( Q <= 200000 );
            CONS( eachElementBetween(L,1,N) );
            CONS( eachElementBetween(R,1,N) );
            CONS( eachElementBetween(X,-1000000,1000000) );
            CONS( alwaysSmaller(L,R) );
        }

    private:
        bool eachElementBetween(const vector<int>& v, int lo, int hi) {
            for (int x : v) {
                if (x < lo || x > hi) {
                    return false;
                }
            }
            return true;
        }

        bool alwaysSmaller(const vector<int>& v, const vector<int>& w) {
            if( v.size() != w.size() ) return false;
            for (int x=0; x<v.size(); x++) {
                if ( v[x] > w[x] ) {
                    return false;
                }
            }
            return true;
        }

        bool alwaysEqual(const vector<int>& v, const vector<int>& w) {
            if( v.size() != w.size() ) return false;
            for (int x=0; x<v.size(); x++) {
                if ( v[x] != w[x] ) {
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
            B.clear();
            L.clear();
            R.clear();
            X.clear();
            F.clear();
        }

        void TestGroup1(){

            Subtasks({1,2,3,4});

            CASE(N=95,Assign(95,A,B,0,0,100));
            CASE(N=96,Assign(96,A,B,0,1,100));
            CASE(N=97,Assign(97,A,B,1,0,100));
            CASE(N=98,Assign(98,A,B,-1,0,100));
            CASE(N=99,Assign(99,A,B,0,-1,100));
            CASE(N=100,Assign(100,A,B,19,-16,100));
            CASE(N=100,Assign(100,A,B,10,10,100));
            CASE(N=100,Assign(100,A,B,-2,2,100));
            CASE(N=100,Assign(100,A,B,-14,-11,100));
            CASE(N=100,Assign(100,A,B,0,0,100));
            CASE(N=96,WorstYES(96,A,B,100));
            CASE(N=96,WorstNO(96,A,B,100));
        }

        void TestGroup2(){

            Subtasks({2,3,4});

            CASE(N=1000,Assign(1000,A,B,0,0,1000000));
            CASE(N=10000,Assign(10000,A,B,0,2,1000000));
            CASE(N=100000,Assign(100000,A,B,2,0,1000000));
            CASE(N=200000-5,Assign(200000-5,A,B,-2,0,1000000));
            CASE(N=200000-4,Assign(200000-4,A,B,0,-2,1000000));
            CASE(N=200000-3,Assign(200000-3,A,B,1934,-1236,1000000));
            CASE(N=200000-2,Assign(200000-2,A,B,102,120,1000000));
            CASE(N=200000-1,Assign(200000-1,A,B,-2232,20211,1000000));
            CASE(N=200000,Assign(200000,A,B,-100000,-11,1000000));
            CASE(N=200000,Assign(200000,A,B,100000,200000,1000000));
            CASE(N=200000,Assign(200000,A,B,0,0,1000000));
            CASE(N=195000,WorstYES(195000,A,B,1000000));
            CASE(N=195000,WorstNO(195000,A,B,1000000));
        }

        void TestGroup3(){

            Subtasks({3,4});

            CASE(N=96,Q=200000,WorstYES(N,A,B,1000000),PointUpdates(96,200000,L,R,X,1,1000000,0,0));
            CASE(N=200000-5,Q=200000,Assign(200000-5,A,B,0,0,1000000),PointUpdates(200000-5,200000,L,R,X,1,1000000,0,0));
            CASE(N=200000-4,Q=200000,Assign(200000-4,A,B,0,3532,1000000),PointUpdates(200000-4,200000,L,R,X,10,1000000,0,3532));
            CASE(N=200000-3,Q=200000,Assign(200000-3,A,B,3243,-352,1000000),PointUpdates(200000-3,200000,L,R,X,100,100000,3243,-352));
            CASE(N=200000-2,Q=200000,Assign(200000-2,A,B,-21434,0,1000000),PointUpdates(200000-2,200000,L,R,X,5,1000000,-21434,0));
            CASE(N=200000-1,Q=200000,Assign(200000-1,A,B,0,0,1000000),PointUpdates(200000-1,200000,L,R,X,10000,1000000,0,0));
            CASE(N=200000,Q=200000,Assign(200000,A,B,0,35343,1000000),PointUpdates(200000,200000,L,R,X,1,10,0,35343));
            CASE(N=195000,Q=200000,WorstYES(195000,A,B,1000000),PointUpdates(195000,200000,L,R,X,1,1000000,0,0));
            CASE(N=195000,Q=200000,WorstNO(195000,A,B,1000000),PointUpdates(195000,200000,L,R,X,100,1000000,-1,0));
        }


        void TestGroup4(){

            Subtasks({4});

            CASE(N=96,Q=200000,WorstYES(N,A,B,1000000),RangeUpdates(96,200000,L,R,X,1,1000000,0,0));
            CASE(N=200000-5,Q=200000,Assign(200000-5,A,B,0,0,1000000),RangeUpdates(200000-5,200000,L,R,X,1,1000000,0,0));
            CASE(N=200000-4,Q=200000,Assign(200000-4,A,B,0,3532,1000000),RangeUpdates(200000-4,200000,L,R,X,10,1000000,0,3532));
            CASE(N=200000-3,Q=200000,Assign(200000-3,A,B,3243,-352,1000000),RangeUpdates(200000-3,200000,L,R,X,100,100000,3243,-352));
            CASE(N=200000-2,Q=200000,Assign(200000-2,A,B,-21434,0,1000000),RangeUpdates(200000-2,200000,L,R,X,5,1000000,-21434,0));
            CASE(N=200000-1,Q=200000,Assign(200000-1,A,B,0,0,1000000),RangeUpdates(200000-1,200000,L,R,X,10000,1000000,0,0));
            CASE(N=200000,Q=200000,Assign(200000,A,B,0,35343,1000000),RangeUpdates(200000,200000,L,R,X,1,10,0,35343));
            CASE(N=195000,Q=200000,WorstYES(195000,A,B,1000000),RangeUpdates(195000,200000,L,R,X,1,1000000,0,0));
            CASE(N=195000,Q=200000,WorstNO(195000,A,B,1000000),RangeUpdates(195000,200000,L,R,X,100,1000000,-1,0));
        }

    private:

        bool eachElementBetween(vector<int>& v, int lo, int hi) {
            for (long long x : v) {
                if (x < lo || x > hi) {
                    return false;
                }
            }
            return true;
        }

        void init(int n,vector<int> &A,vector<int> &B){
            F.clear();
            for(int i=0; i<=n; i++)
                F.pb(0);
            F[1] = B[1] - A[1];
            for(int i=2; i<=n; i++)
                F[i] = (long long)B[i] - A[i] + F[i-1] - F[i-2];
        }

        void process(int id,long long x,int n,long long &F1,long long &F2){
            int y = ( n - id ) % 6;
            if( y == 0 || y == 1 ) F2 -= x;
            if( y == 3 || y == 4 ) F2 += x;
            if( y == 2 || y == 5 ) F2 += 0;

            if( id <= n - 1 ){
                y = ( n - 1 - id ) % 6;
                if( y == 0 || y == 1 ) F1 -= x;
                if( y == 3 || y == 4 ) F1 += x;
                if( y == 2 || y == 5 ) F1 += 0;
            }
        }

        void fast_update(int l,int r,long long x,int n,long long &F1,long long &F2){
            for(int i=r; i>=l; i--){
                process(i,x,n,F1,F2);
                if( i % 6 == l % 6 && i < n - 1 )
                    break;
            }
        }

        void Assign(int n,vector<int> &A, vector<int> &B,int D1,int D2,int limit){
            while( true ){
                A.clear();
                B.clear();
                F.clear();
                F.pb(0);
                vector<int> D;

                for(int i=1; i<=n; i++){
                    if( i < n - 2 ) D.pb( rnd.nextInt(-(limit/3-10),limit/3-10) );
                    if( i == n - 1 ) D.pb(D1);
                    if( i == n ) D.pb(D2);

                    A.pb(1);
                    B.pb(1);

                    if( i > 1 ) F.pb( (long long)B[i-1] - A[i-1] + F[i-1] - F[i-2] );
                        else F.pb( (long long)B[i-1] - A[i-1] );

                    long long toch = D.back() - F.back();
                    if( toch >= 0 ) B[i-1] += toch;
                        else A[i-1] -= toch;

                    if( A[i-1] > limit || B[i-1] > limit ) break;
                    int toadd = rnd.nextInt( 0 , min( limit - A[i-1] , limit - B[i-1] ) );
                    A[i-1] += toadd;
                    B[i-1] += toadd;

                    if( i > 1 ) F[i] = (long long)B[i-1] - A[i-1] + F[i-1] - F[i-2];
                        else F[i] = (long long)B[i-1] - A[i-1];
                }

                if( eachElementBetween(A,1,limit) && eachElementBetween(B,1,limit) ) break;
            }
            init(n,A,B);
        }

        void WorstYES(int n,vector<int> &A,vector<int> &B,int limit){
            for(int i=0; i<n/2; i++){
                A.pb(1);
                B.pb(1);
                if( i % 6 == 0 ) A[i] = limit;
                if( i % 6 == 3 ) B[i] = limit;
            }
            for(int i=n/2; i<n; i++){
                A.pb(1);
                B.pb(1);
                if( i % 6 == 0 ) B[i] = limit;
                if( i % 6 == 3 ) A[i] = limit;
            }
            init(n,A,B);
        }

        void WorstNO(int n,vector<int> &A,vector<int> &B,int limit){
            for(int i=0; i<n/2; i++){
                A.pb(1);
                B.pb(1);
                if( i % 6 == 0 ) A[i] = limit;
                if( i % 6 == 3 ) B[i] = limit;
            }
            for(int i=n/2; i<n; i++){
                A.pb(1);
                B.pb(1);
                if( i % 6 == 0 ) B[i] = limit;
                if( i % 6 == 3 ) A[i] = limit;
            }
            A[0]--;
            init(n,A,B);
        }

        void RangeUpdates(int n,int q,vector<int> &L,vector<int> &R,vector<int> &X,int pno,int limit,long long F1,long long F2){

            while( X.size() < q ){
                int y = rnd.nextInt(1,pno);
                for(int t=1; t<=y; t++){

                    int nl = rnd.nextInt(1,n);
                    int nr = rnd.nextInt(nl,n);
                    int nx = rnd.nextInt(1,limit);

                    fast_update(nl,nr,nx,n,F1,F2);

                    if( X.size() < q ){
                        L.pb(nl);
                        R.pb(nr);
                        X.pb(nx);
                    }
                }
                while( F1 != 0 ){
                    int sub = rnd.nextInt(0,(n-3)/6);
                    int add = rnd.nextInt(0,sub);

                    int nl = ( n - 2 ) - sub * 6;
                    int nr = nl + add * 6;
                    long long nx = F1;
                    if( abs(nx) > limit ){
                        if( nx > 0 ) nx = limit;
                            else nx = -limit;
                    }


                    fast_update(nl,nr,nx,n,F1,F2);
                    if( X.size() < q ){
                        L.pb(nl);
                        R.pb(nr);
                        X.pb(nx);
                    }
                    if( X.size() == q ) break;
                }
                while( F2 != 0 ){
                    int sub = rnd.nextInt(0,(n-4)/6);
                    int add = rnd.nextInt(0,sub);

                    int nl = ( n - 3 ) - sub * 6;
                    int nr = nl + add * 6;
                    long long nx = -F2;
                    if( abs(nx) > limit ){
                        if( nx > 0 ) nx = limit;
                            else nx = -limit;
                    }


                    fast_update(nl,nr,nx,n,F1,F2);

                    if( X.size() < q ){
                        L.pb(nl);
                        R.pb(nr);
                        X.pb(nx);
                    }
                    if( X.size() == q ) break;
                }
            }
        }

        void PointUpdates(int n,int q,vector<int> &L,vector<int> &R,vector<int> &X,int pno,int limit, long long F1, long long F2){

            while( X.size() < q ){
                int y = rnd.nextInt(1,pno);
                for(int t=1; t<=y; t++){

                    int nl = rnd.nextInt(1,n);
                    int nr = nl;
                    int nx = rnd.nextInt(1,limit);

                    fast_update(nl,nr,nx,n,F1,F2);

                    if( X.size() < q ){
                        L.pb(nl);
                        R.pb(nr);
                        X.pb(nx);
                    }
                }
                while( F1 != 0 ){
                    int sub = rnd.nextInt(0,(n-3)/6);
                    int add = 0;

                    int nl = ( n - 2 ) - sub * 6;
                    int nr = nl + add * 6;
                    int nx = F1;
                    if( abs(nx) > limit ){
                        if( nx > 0 ) nx = limit;
                            else nx = -limit;
                    }


                    fast_update(nl,nr,nx,n,F1,F2);
                    if( X.size() < q ){
                        L.pb(nl);
                        R.pb(nr);
                        X.pb(nx);
                    }
                    if( X.size() == q ) break;
                }
                while( F2 != 0 ){
                    int sub = rnd.nextInt(0,(n-4)/6);
                    int add = 0;

                    int nl = ( n - 3 ) - sub * 6;
                    int nr = nl + add * 6;
                    int nx = -F2;
                    if( abs(nx) > limit ){
                        if( nx > 0 ) nx = limit;
                            else nx = -limit;
                    }


                    fast_update(nl,nr,nx,n,F1,F2);

                    if( X.size() < q ){
                        L.pb(nl);
                        R.pb(nr);
                        X.pb(nx);
                    }
                    if( X.size() == q ) break;
                }
            }
        }
};
