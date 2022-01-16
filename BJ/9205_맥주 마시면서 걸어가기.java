import java.util.*;
import java.io.*;

public class Main {
	static class box{
		int x;
		int y;
		box(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static int t, n, p[];
	static box b[];
	static boolean isVisited[];
	static ArrayList<ArrayList<Integer>> lists;
	static Queue<Integer>q = new LinkedList<>();
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static void init() throws Exception{
		n = Integer.parseInt(br.readLine());
		b = new box[n+2];
		p = new int[n+2];
		isVisited = new boolean[n+2];
		
		lists = new ArrayList<>();
		StringTokenizer st;
		for (int i = 0; i < n+2; i++) {
			lists.add(new ArrayList<>());
			st = new StringTokenizer(br.readLine());
			b[i] = new box(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
		} // 삽입 완료
		
		for (int i = 0; i < n+1; i++) {
			
			for (int j = i+1; j < n+2; j++) {
				int x = Math.abs(b[i].x - b[j].x);
				int y = Math.abs(b[i].y - b[j].y);
				
				if(Math.abs(x+y) <= 1000) {
					lists.get(i).add(j);
					lists.get(j).add(i);
				}
			}
		} // 리스트에도 삽입 완료
		
	}
	static String bfs() {
		while(!q.isEmpty()) {
			int x= q.peek();
			q.poll();
			
			if(x == n+1) return("happy");
			
			for (int i = 0; i < lists.get(x).size(); i++) {
				if(!isVisited[lists.get(x).get(i)]) {
					q.add(lists.get(x).get(i));
					isVisited[lists.get(x).get(i)] = true;
				}
			}
		}
		return("sad");
	}
	public static void main(String[] args) throws Exception{
		t = Integer.parseInt(br.readLine());
		for (int i = 0 ; i < t; i++) {
			init();
			q.add(0);
			System.out.println(bfs());
			q.clear();
		}
		
	}
}
