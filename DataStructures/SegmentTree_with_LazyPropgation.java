

import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.String.*;

public class Main {
    
    static int n;
    static int [] a,seg,lazy;
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        StringTokenizer tk;

        //read n and the array a[n]
        //define segment tree array, seg of size 4*N
        //for all methods we call (p=1,s=0,e=n-1)
    }
    
    static void check(int p,int s,int e) {
        if(lazy[p]!=0) {
            seg[p] += lazy[p];
            if(s!=e) {
                lazy[2*p] += lazy[p];
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }
    
    static void build(int p,int s,int e) {
        check(p,s,e);
        
        if(s==e) {
            seg[p] = a[s];
            return;
        }
        
        build(2*p,s,(s+e)/2);
        build(2*p+1,(s+e)/2+1,e);
        
        seg[p] = min(seg[2*p], seg[2*p+1]);
    }
    
    static void update(int p,int s,int e,int i,int v) {
        check(p,s,e);
        
        if(s==e) {
            seg[p] = v;
            return;
        }
        
        if(i<=(s+e)/2) update(2*p,s,(s+e)/2,i,v);
        else update(2*p+1,(s+e)/2+1,e,i,v);
        
        seg[p] = min(seg[2*p],seg[2*p+1]);
    }
    
    static void update(int p,int s,int e,int a,int b,int v) {
        check(p,s,e);
        
        if(s>=a && e<=b) {
            seg[p] += v;
            
            if(s!=e) {
                lazy[2*p] += v;
                lazy[2*p+1] += v;
            }
            
            return;
        }
        
        if(s>b || e<a)
            return;
        
        update(2*p,s,(s+e)/2,a,b,v);
        update(2*p+1,(s+e)/2+1,e,a,b,v);
        
        seg[p] = min(seg[2*p],seg[2*p+1]);
    }
    
    static int get(int p,int s,int e,int a,int b) {
        check(p,s,e);
        
        if(s>=a && e<=b)
            return seg[p];
        
        if(s>b || e<a)
            return Integer.MAX_VALUE; 
        
        return min(get(2*p,s,(s+e)/2,a,b), get(2*p+1,(s+e)/2+1,e,a,b));
    }
}