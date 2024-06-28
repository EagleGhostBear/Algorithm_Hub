import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int start;
    int end;

    Node(int start, int end){
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Node right){
        if(this.end < right.end){return -1;}
        if(this.end > right.end){return 1;}

        if(this.start < right.start){return -1;}
        if(this.start > right.start){return 1;}

        return -1;
    }
}

public class Main {
    static int n;
    static int cnt = 0;
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(bf.readLine());
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            pq.add(new Node(a, b));
        }

        int endt = 0;

        while(!pq.isEmpty()){
            Node now = pq.poll();

            if(endt <= now.start){
                cnt += 1;
                endt = now.end;
            }
        }

        System.out.println(cnt);
    }
}