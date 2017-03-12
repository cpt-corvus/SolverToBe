

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
    static int [] a,seg;
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        StringTokenizer tk;

        //read n and the array a[n]
        //define segment tree array, seg of size 4*N
        //for all methods we call (p=1,s=0,e=n-1)
    }
    
    static void build(int p,int s,int e) {
        if(s==e) {
            seg[p] = a[s];
            return;
        }
        
        build(2*p,s,(s+e)/2);
        build(2*p+1,(s+e)/2+1,e);
        
        seg[p] = min(seg[2*p], seg[2*p+1]);
    }
    
    static void update(int p,int s,int e,int i,int v) {
        if(s==e) {
            seg[p] = v;
            return;
        }
        
        if(i<=(s+e)/2) update(2*p,s,(s+e)/2,i,v);
        else update(2*p+1,(s+e)/2+1,e,i,v);
        
        seg[p] = min(seg[2*p],seg[2*p+1]);
    }
    
    static int get(int p,int s,int e,int a,int b) {
        if(s>=a && e<=b)
            return seg[p];
        
        if(s>b || e<a)
            return Integer.MAX_VALUE; 
        
        return min(get(2*p,s,(s+e)/2,a,b), get(2*p+1,(s+e)/2+1,e,a,b));
    }
}