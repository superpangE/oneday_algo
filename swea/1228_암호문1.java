package day0807;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Test {
	
	static public Node head;
	
	static public class Node{			//노드 클래스
		int data;
		Node link;
		
		public Node(int data) {
			super();
			this.data = data;
		}
		
		public Node(int data, Node link) {
			super();
			this.data = data;
			this.link = link;
		}
	}
	

	static public void addFirst(int data) {		// 노드 처음에 넣기
		Node newNode = new Node(data, head);
		head = newNode;
	}
	
	static public Node getLast() {				// 노드 마지막이 어딘지 찾기
		for (Node currNode=head; currNode != null; currNode = currNode.link) {
			if (currNode.link == null)
				return (currNode);
		}
		return (null);
	}
	
	static public void addEnd(int data) {		// 노드 마지막에 넣기
		if (head == null) {
			addFirst(data);
			return ;
		}
		
		Node lastNode = getLast();
		Node newNode = new Node(data);
		
		lastNode.link = newNode;	
	}
	
	static public void insertAfter(int data, int rank) {
		if (rank == 0) {
			addFirst(data);
			return;
		}
		Node currNode = head;
		for (int i = 0; i < rank - 1; i++) {
			currNode = currNode.link;
		}
		Node inputNode = new Node(data);
		inputNode.link = currNode.link;
		currNode.link = inputNode;
	}
	
	static public void printList() {
		Node currNode=head;
		for (int i = 0; i < 10; i++) {
			System.out.print(currNode.data + " ");
			currNode = currNode.link;
		}
		System.out.println();
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int TC = 1; TC <= 10; TC++) {
			int tmp;
			String text;
			tmp = Integer.parseInt(br.readLine());
			text = br.readLine();
			StringTokenizer st = new StringTokenizer(text, " ");
			for (int i = 0; i < tmp; i++) {
				addEnd(Integer.parseInt(st.nextToken()));
			}
			tmp = Integer.parseInt(br.readLine());
			text = br.readLine();
			st = new StringTokenizer(text, "I");
			for (int i = 0; i < tmp; i++) {
				StringTokenizer tmpst = new StringTokenizer(st.nextToken());
				int loc, num, val;
				loc = Integer.parseInt(tmpst.nextToken());
				num = Integer.parseInt(tmpst.nextToken());
				for (int k = 0; k < num; k++) {
					val = Integer.parseInt(tmpst.nextToken());
					insertAfter(val, loc++);
				}
			}
			System.out.print("#" + TC + " ");
			printList();
			head = null;
		}
	}
}
