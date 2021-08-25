package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class SWEA_hana {
/*
 * N개 만큼의 섬들의 간선을 내가 임의로 만든다
 * class로 간선(출발지, 도착지, 비용) 순으로 만든다
 * PriorityQueue에 간선을 전부 집어넣는다 (오름차순으로 됨)
 * Queue에서 하나뺐을 때 마다 find() 함수를 사용해서 두개가 연결 되어잇는지 확인
 * 연결을 했다(union()) 그리고 나서 모두가 연결되어있는지 확인 0~N
 * 끝까지 다돌기
 * 
 */
	static class line implements Comparable<line>{
		int start;
		int goal;
		double weight;
		line(int s, int g, double w){
			this.start = s;
			this.goal = g;
			this.weight = w;
		}
		@Override
		public int compareTo(line o) {
			return (int)(this.weight - o.weight);
		}
	}
	static class pos{
		int x, y;
		pos(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static PriorityQueue<line>q = new PriorityQueue<>();
	static int T, N, tmparr[];
	static double mul, res;
	static int p[];
	static pos[] arr;
	
	static int find(int x) {
		if (x == p[x]) return (x);
		return (p[x] = find(p[x]));
	}
	
	static void union() {
		while (!q.isEmpty()) {
			int s = q.peek().start;
			int g = q.peek().goal;
			double w = q.peek().weight;
			q.poll();
			
			int f_s = find(s);
			int f_g = find(g);
			if (f_s == f_g) continue;
			p[f_s] = f_g;
			res += w;
		}
	}
	
	static void make() {
		for (int i = 0; i < N; i++) {
			p[i] = i;
			for (int j = i + 1; j < N; j++) {
				double tmp = (((double)(arr[i].x - arr[j].x) * (double)(arr[i].x - arr[j].x)) + ((double)(arr[i].y - arr[j].y) * (double)(arr[i].y - arr[j].y)));
				q.add(new line(i, j, tmp));
				
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		for (int TC= 1; TC <= T; TC++) {
			res = 0;
			N = Integer.parseInt(br.readLine());
			p = new int[N];
			arr = new pos[N];
			tmparr = new int[N];
			
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++)
				tmparr[i] = Integer.parseInt(st.nextToken());	// x 좌표 tmparr 에 삽입
			
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++)
				arr[i] = new pos(tmparr[i], Integer.parseInt(st.nextToken()));		// arr함수 안에 x, y 좌표 삽입
			mul = Double.parseDouble(br.readLine());		// 입력 완료
			
			make();
			union();
			System.out.println("#" + TC + " " + Math.round(res * mul));
		}
	}

}
