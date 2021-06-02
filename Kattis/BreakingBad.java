import java.util.*;

public class BreakingBad {

    static List<String> list;
    static Set<String> a, b;
    static HashMap<String, Set<String>> map;
    static boolean flag;

    static void dfs(String current){

        if(!a.contains(current) && !b.contains(current)){
            a.add(current);
        }

        for(String s : map.get(current)){

            if(a.contains(current) && !b.contains(s) && !a.contains(s)){
                b.add(s);
                dfs(s);
            }

            else if(b.contains(current) && !a.contains(s) && !b.contains(s)){
                a.add(s);
                dfs(s);
            }

            else if((a.contains(current) && a.contains(s)) || (b.contains(current) && b.contains(s))){
                flag = false;
                return;
            }
        }

    }

    public static void main(String args[]){

        // init
        flag = true;
        Scanner sc = new Scanner(System.in);
        list = new ArrayList<>();
        a = new HashSet<>();
        b = new HashSet<>();
        map = new HashMap<>();


        int n;
        n = sc.nextInt();
        for(int i = 0 ; i < n ; i++){
            String s = sc.next();
            list.add(s);
            map.put(s, new HashSet<>());
        }

        int m;
        m = sc.nextInt();
        for(int i = 0 ; i < m ; i++){
            String x = sc.next();
            String y = sc.next();
            map.get(x).add(y);
            map.get(y).add(x);
        }

        for(String s : list){
            dfs(s);
        }


        if(flag){

            for(String s : a){
                System.out.print(s + " ");
            }
            System.out.println();
            for(String s : b){
                System.out.print(s + " ");
            }
        }
        else{
            System.out.println("impossible");
        }

    }
}
