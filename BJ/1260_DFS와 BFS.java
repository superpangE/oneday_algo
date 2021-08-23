package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
/*
 * class Pair 로 받아서 x, y 순서로 정렬부터 해야할 것 같음
 * x, y 오름차순으로 정렬한 데이터를 ArrayList 에 집어넣을 예정
 * ArrayList[] 를 N 만큼 정적으로 할당한 뒤, 해당 리스트가 닿는 부분을 가변적으로 넣어줌
 * 일반적인 dfs 와 bfs 활용
 */
public class BJ_1260 {
	
	static class Pair implements Comparable<Pair>{
		int x;
		int y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		
		@Override
		public int compareTo(Pair o) {
			if (this.x == o.x)
				return (this.y - o.y);
			return (this.x - o.x);
		}
	}
	static int N, M, start, a, b;
	static ArrayList<Integer> list[];
	static Pair tmparr[];
	static Queue<Integer>q = new LinkedList<>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		start = Integer.parseInt(st.nextToken());
		list = new ArrayList[N + 1];
		tmparr = new Pair[M];
		for (int i = 1 ; i <= N; i++)
			list[i] = new ArrayList<>();
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			tmparr[i] = new Pair(a, b);
		}		// tmparr 에 Pair 전체가 들어가있는 상태
		
		Arrays.sort(tmparr);		// tmparr 에 정렬되어 들어가 있는 상태
		/*
		 * 다음과 같은 반례 있어서 정렬 다시해줘야 할듯
		 * 3 3 1
		 * 3 2
		 * 2 1
		 * 1 3
		 */
		
		for (int i = 0; i < tmparr.length; i++) {
			int fir = tmparr[i].x;
			int sec = tmparr[i].y;
			
			list[fir].add(sec);
			list[sec].add(fir);
		}		// list 에 순서대로 다 집어넣음.
		for (int i = 1 ; i < list.length; i++) {
			Collections.sort(list[i]);
		}
		
		// DFS 사용
		dfs(start, new boolean[N + 1]);
		System.out.println();
		
		// BFS 사용
		boolean chk[] = new boolean[N + 1];
		q.add(start);
		chk[start] = true;
		bfs(chk);
		
	}
	
	static void dfs(int idx, boolean chk[]) {
		chk[idx] = true;
		System.out.print(idx + " ");
		for (int i = 0; i < list[idx].size(); i++) {
			if (chk[list[idx].get(i)] == false) {
				dfs(list[idx].get(i), chk);
			}
		}
	}
	
	static void bfs(boolean chk[]) {
		while (!q.isEmpty()) {
			int idx = q.poll();
			System.out.print(idx+ " ");
			for (int i = 0; i < list[idx].size(); i++) {
				if (chk[list[idx].get(i)] == false) {
					chk[list[idx].get(i)] = true;
					q.add(list[idx].get(i));
				}
			}
		}
		
	}
}
