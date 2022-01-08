import java.util.*;
import java.io.*;

public class Main {
	static class box{
		int spot;
		int cnt;
		box(int spot, int cnt){
			this.spot = spot;
			this.cnt = cnt;
		}
	}
	static boolean arr[][], isVisited[];
	static Queue<box>q = new LinkedList<>();
	static int N, s, e;
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		arr = new boolean[N+1][N+1];
		isVisited = new boolean[N+1];
		
		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		isVisited[s] = true;
		
		int num = Integer.parseInt(br.readLine());
		for (int i = 0 ; i < num; i++) {
			st = new StringTokenizer(br.readLine());
			int tmp1 = Integer.parseInt(st.nextToken());
			int tmp2 = Integer.parseInt(st.nextToken());
			
			arr[tmp1][tmp2] = true;
			arr[tmp2][tmp1] = true;
		}
		q.add(new box(s, 1));
	}
	
	static int bfs() {
		while(!q.isEmpty()) {
			int start = q.peek().spot;
			int cnt = q.peek().cnt;
			q.poll();
			
			for (int i = 1; i < N+1; i++) {
				if(arr[start][i] && !isVisited[i]) {
					if(i == e) return (cnt);
					isVisited[i]= true;
					q.add(new box(i, cnt+1));
				}
			}
		}
		
		return (-1);
	}
	
	public static void main(String[] args) throws Exception{
		init();
		System.out.println(bfs());
	}
}
