package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
/*
 * Integer, boolean를 받을 수 있는 Queue를 만든다
 * 확인하고 싶은 쪽만 boolean 을 true 해서 넣음
 * 한번 돌때마다 전체 Queue를 확인해서 이것보다 높은 순위가 있는지 본다
 * 배열을 하나 만들어서 내림차순으로 정렬 후, 맞는지 확인
 * 
 */
public class BJ_1966 {
	
	static class Pair{
		int first;
		boolean second;
		
		Pair(int f, boolean s){
			this.first = f;
			this.second = s;
		}
	}
	
	static int N, M, T;
	static Integer arr[];
	static Queue<Pair>q = new LinkedList<>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		T = Integer.parseInt(br.readLine());
		for (int TC = 0; TC < T; TC++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			arr = new Integer[N];
			int point = 0;
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				point = Integer.parseInt(st.nextToken());
				if(i == M) {
					q.add(new Pair(point, true));
				}
				else {
					q.add(new Pair(point, false));
				}
				arr[i] = point;
				
			}			// 입력 완료
			
			Arrays.sort(arr, Comparator.reverseOrder());
			int k = 0;
			while (!q.isEmpty()) {
				int val = q.peek().first;
				boolean spot = q.peek().second;
				q.poll();
				if (arr[k] == val) {
					if (spot == true) {
						System.out.println(++k);
						break;
					}
					k++;
				}
				else {
					q.add(new Pair(val, spot));
				}
			}
			q.clear();
			
		}
		
	}
}
