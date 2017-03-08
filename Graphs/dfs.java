
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
        dfs(0); // or    dfs_stack(0);
        
    }
    
    static void dfs(int u) {
        vis[u] = true;
        
        for(int w : g[u]) 
            if(!vis[w]) 
                dfs(w);
    }
    
    static void dfs_stack(int u) {
        Stack<Integer> s = new Stack();
        
        vis[u] = true;
        s.add(u);
        
        while(!s.isEmpty()) {
            int v = s.pop();
            
            for(int w : g[v]) {
                if(!vis[w]) {
                    vis[w] = true;
                    s.add(w);
                }
            }
        }
    }
}

