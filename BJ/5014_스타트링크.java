package day1011;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BJ_5014 {
	static class box{
		int x;
		int cnt;
		box(int x, int cnt){
			this.x = x;
			this.cnt = cnt;
		}
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int F, S, G, U, D;
	static boolean isVisited[];
	static Queue<box>q = new LinkedList<>();
	
	public static void main(String[] args) throws Exception{
		StringTokenizer st = new StringTokenizer(br.readLine());
		F = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		U = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		
		isVisited = new boolean[F + 1];
		q.add(new box(S, 0));
		isVisited[S] = true;
		if(S == G) {
			System.out.println("0");
			return ;
		}
		while(!q.isEmpty()) {
			int x = q.peek().x;
			int cnt = q.peek().cnt;
			q.poll();
			
			if(x + U <= F && !isVisited[x+U]) {
				isVisited[x+U] = true;
				if(x+U == G) {
					System.out.println(cnt+1);
					return;
				}
				q.add(new box(x+U, cnt+1));
			}
			if(x - D > 0 && !isVisited[x-D]) {
				isVisited[x-D] = true;
				if(x-D == G) {
					System.out.println(cnt+1);
					return ;
				}
				q.add(new box(x-D, cnt+1));
			}
		}
		System.out.println("use the stairs");
	}
}
