import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.String.*;

public class Main {

    static final int INF = Integer.MAX_VALUE;
    static int n, m;
    static List<pair> [] g;
    static int [] dist;
    
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        
        g = new List[n];
        for(int i=0; i<n; i++)
            g[i] = new ArrayList();
        
        for(int i=0; i<m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            
            g[a].add(new pair(b,c)); 
            g[b].add(new pair(a,c)); 
        }
        
        dijkstra(0);
    }
    
    static void dijkstra(int s) {
        dist = new int[n];
        Arrays.fill(dist,INF);
        dist[s] = 0;
        
        Queue<node> pq = new PriorityQueue();
        pq.add(new node(s,0));
        
        while(!pq.isEmpty()) {
            node u = pq.remove();
            
            for(int i=0; i<g[u.num].size(); i++) {
                int v = g[u.num].get(i).f;
                int c = g[u.num].get(i).s;
                
                if(dist[v] > dist[u.num] + c) {
                    dist[v] = dist[u.num] + c;
                    pq.add(new node(v,dist[v]));
                }
            }
        }
    }
}

class pair {
    int f,s;
    
    public pair(int f,int s) {
        this.f = f;
        this.s = s;
    }
}

class node implements Comparable<node> {
    int num,cost;
    
    public node(int num,int c) {
        this.num = u;
        this.cost = c;
    }
    
    @Override
    public int compareTo(node n) {
        if(cost != n.cost)
            return cost - n.cost;
        return num-n.num;
    }
}
