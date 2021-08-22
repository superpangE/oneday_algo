package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
/*
 * push 는 Stack에 정의되어 있고, Vector의 addElement 호출
 * add 는 Vector에 정의되어 있음
 */
public class BJ_10773 {
	static Stack<Integer> s = new Stack<>();
	static int K, N;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int res = 0;
		K = Integer.parseInt(br.readLine());
		for (int i = 0 ; i < K ; i++) {
			N = Integer.parseInt(br.readLine());
			if (N == 0)
				s.pop();
			else s.push(N);
		}
		while(!s.isEmpty()) {
			res += s.lastElement();
			s.pop();
		}
		System.out.println(res);
	}

}
