
import java.util.*;

public class Main {

    static int n,m;
    static List<Integer> [] g;
    static boolean [] vis;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        
        g = new List[n];
        for(int i=0; i<n; i++)
            g[i] = new ArrayList();
        
        for(int i=0; i<m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            
            g[a].add(b); // a -> b
            g[b].add(a); // b -> a  (for un-directed graph)
        }
        
        vis = new boolean[n];
        bfs(0);
        
    }
    
    
    static void bfs(int u) {
       	Queue<Integer> q = new LinkedList();
        
        vis[u] = true;
        q.add(u);
        
        while(!q.isEmpty()) {
            int v = q.remove();
            
            for(int w : g[v]) {
                if(!vis[w]) {
                    vis[w] = true;
                    q.add(w);
                }
            }
        }
    }
}

