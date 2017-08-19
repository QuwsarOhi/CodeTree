//QuwsarOhi

import java.io.*;
import java.util.*;

class DataStructure {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
		
		//Vector
		
        Vector<Integer> v = new Vector<Integer>();
        for(int i = 0; i < 100; i++)
			v.add(i);
		
		//v.set(112, -1);		will cause error!
		//System.out.println(v.get(112));
		
		System.out.println("Vector size : " + v.size());
		v.clear();		//clearing vector;
		
		//Stack
		
		Stack<Integer> s = new Stack<Integer>();
		for(int i = 0; i < 10; i++)
			s.push(i);
		while(!s.empty()) {
			System.out.println(s.peek());
			s.pop();
		}
		s.clear();		//clearing stack;
		
		//Queue AND Deque
		
		Queue<Integer> q = new LinkedList<Integer>();
		Deque<Integer> d = new LinkedList<Integer>();
		
		for(int i = 0; i < 10; i++)
			q.add(i);
		System.out.println("Queue has : " + q);
		System.out.println("Queue Size : " + q.size());
		for(int i = 0; i < 10; i++) {
			System.out.println(q.peek());
			q.remove();
		}
		q.clear();		//clearing queue
		
		for(int i = 0; i < 5; i++)
			d.addFirst(i);
		for(int i = 5; i < 10; i++)
			d.addLast(i);
		System.out.println("Dequeue : " + d);
		d.pollFirst();		//removing first object
		d.pollLast();		//removing last object
		System.out.println("First : " + d.getFirst() + " Last : " + d.getLast() + " Size : " + d.size());
		d.clear();			//clearing deque
		
		//Map AKA TreeMap
		
		TreeMap<String, Integer> map = new TreeMap<String, Integer>();
		
		map.put("asd", 10);
		map.put("asr", 23);
		map.put("erty",-1);
		map.put("rt", 100);
		
		//Set set = map.entrySet();		//Converting map to set to iterate through it
		//Iterator it = set.iterator();	//making iterator of that set
		
		//Collection c = map.values();	//use upper commented method or this method
		//Collection c = map.key();		//if we want to itera
		Iterator it = map.values().iterator();
		
		System.out.println("Iterating over Map values : ");
		while(it.hasNext()){
			//Map.Entry ME = (Map.Entry)it.next();	//converting into map entry;
			//System.out.println(ME.getKey() + "  " + ME.getValue());
			System.out.print(it.next() + " + ");
		}
		System.out.println();
		System.out.println(map.keySet());
		System.out.println(map.values());
		System.out.println(map.get("asd"));  	//getting value by key
		
		System.out.println(map.containsKey("AD"));	//returns true if found
		
		map.clear(); 	//clearing map
		
		//Set AKA TreeSet
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		
		for(int i = 0; i < 10; i++)
			set.add(i);
			
		Iterator It = set.iterator();
		System.out.println("Iterating over Set values : ");
		while(It.hasNext())
			System.out.print(It.next() + " + ");
		System.out.println();
		
		System.out.println("Set size : " + set.size());
		System.out.println(set.contains(5));		//returns true if the value is in set
		System.out.println(set.headSet(5));			//returns a set of values which are less than the given number
		System.out.println(set.tailSet(5));			//returns a set of values which are greater or equal than the given number
		set.clear();			//clearing set;
		
		//Multi dimentional array
		
		int arr[][] = new int[5][];		//the first size must be declared;
		for(int i = 0; i < 5; i++) {
			arr[i] = new int[6];			//then the array is 5*6
			for(int j = 0; j < 6; j++)
				arr[i][j] = j;
		}
		
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 6; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
    }
}