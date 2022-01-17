import java.util.*;
import java.io.*;

public class Main {
	static class box implements Comparable<box>{
		int x;
		int y;
		box(int x, int y){
			this.x = x;
			this.y = y;
		}
		
		@Override
		public int compareTo(box o) {
			return (this.y - o.y);
		}
	}
	static class box2 implements Comparable<box2>{
		int x;
		int y;
		box2(int x, int y){
			this.x = x;
			this.y = y;
		}
		
		@Override
		public int compareTo(box2 o) {
			return (this.x - o.x);
		}
	}
	static PriorityQueue<box>pq = new PriorityQueue<>();
	static PriorityQueue<box2>pq2 = new PriorityQueue<>();
	static int N, maxv;
	static void init() throws Exception{
		BufferedReader br =new  BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			pq2.add(new box2(x, y));
			
		}
		for (int i = 0; i < N; i++) {
			int x = pq2.peek().x;
			int y = pq2.peek().y;
			pq2.poll();

			while(!pq.isEmpty() && pq.peek().y <= x) {
				pq.poll();
			}
			pq.add(new box(x, y));
			if(maxv < pq.size()) maxv = pq.size();
		}
	}
	public static void main(String[] args) throws Exception{
		init();
		System.out.println(maxv);
	}
}
