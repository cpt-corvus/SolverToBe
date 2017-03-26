

import java.io.*;
import java.util.*;

public class Main {

    static int [] p;
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(),m = scn.nextInt();
        
        p = new int[n];
        for(int i=0; i<n; i++)
            p[i] = i;
        
        while(m-- > 0) {
            int a = scn.nextInt(),b = scn.nextInt();
            
            a = find(a);
            b = find(b);
            
            if(a != b) {
                p[a] = b;
            }
        }
    }
    
    static int find(int u) {
        if(u==p[u])
            return u;
        
        return p[u] = find(p[u]);
    }
}
