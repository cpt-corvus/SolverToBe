
//-------------------------------------------------------------------------------------------
//----------------------------------- unweighted graph --------------------------------------
//-------------------------------------------------------------------------------------------

public class Main {

    static int n,m;
    static List<Integer> [] g;
    
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
            
            g[a].add(b); // a -> b
            g[b].add(a); // b -> a  (for un-directed graph)
        }
    } 
}




//-------------------------------------------------------------------------------------------
//------------------------------------- weighted graph --------------------------------------
//-------------------------------------------------------------------------------------------


public class Main {

    static int n,m;
    static List<node> [] g;
    
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
            
            g[a].add(new node(b,c)); // a -> b with cost c
            g[b].add(new node(a,c)); // b -> a with cost c (for un directed graph)
        }
    } 
}

class node {
    int u,cost;
    
    public node(int u,int cost) {
        this.u = u;
        this.cost = cost;
    }
}