2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	struct node *prev_node;
	int info;
	struct node *next_node;
};

struct node *create_list(struct node *begin);
void display(struct node *begin);
struct node *addtoemptylist(struct node *begin,int data_element);
struct node *addatbeglist(struct node *begin,int data_element);
struct node *addatendlist(struct node *begin,int data_element);
struct node *addafterlist(struct node *begin,int data_element,int item_pos);
struct node *addbeforelist(struct node *begin,int data_element,int item_pos);
struct node *deletenode(struct node *begin,int data_element);
struct node *reverselist(struct node *begin);

int main()
{
	int option,data_element,item_pos;
	struct node *begin=NULL;
	while(1)
	{
		cout<<"\n1.Create A New Doubly Linked List\n";
		cout<<"2.Display the Doubly Linked List\n";
		cout<<"3.Add to an Empty Doubly Linked List\n";
		cout<<"4.Add at Starting of the Doubly Linked List\n";
		cout<<"5.Add at Ending\n";
		cout<<"6.Add After a Node\n";
		cout<<"7.Add Before a Node\n";
		cout<<"8.Delete a Node\n";
		cout<<"9.Reverse the Doubly Linked List\n";
		cout<<"10.Exit\n";
		cout<<"Enter your option : ";
		cin>>option;

		switch(option)
		{
		 case 1:
			begin=create_list(begin);
			break;
		 case 2:
			display(begin);
			break;
		 case 3:
			cout<<"Enter the element:";
			cin>>data_element;
			begin=addtoemptylist(begin,data_element);
			break;
		 case 4:
	        	cout<<"Enter the element:";
			cin>>data_element;
			begin=addatbeglist(begin,data_element);
			break;
		 case 5:
			cout<<"Enter the element:";
			cin>>data_element;
			begin=addatendlist(begin,data_element);
			break;
		 case 6:
			cout<<"Enter the element:";
			cin>>data_element;
			cout<<"Enter the element after which to insert : ";
			cin>>item_pos;
			begin=addafterlist(begin,data_element,item_pos);
			break;
		 case 7:
			cout<<"Enter the element: ";
			cin>>data_element;
			cout<<"Enter the element before which to insert : ";
			cin>>item_pos;
			begin=addbeforelist(begin,data_element,item_pos);
			break;
		 case 8:
			cout<<"Enter the element to be Deleted : ";
			cin>>data_element;
			begin=deletenode(begin,data_element);
	   		break;
		 case 9:
		 	begin=reverselist(begin);
			break;
		 case 10:
			exit(1);
		 default:
			cout<<"Wrong option\n";
	}
   }

   return 0;
}

struct node *create_list(struct node *begin)
{
	int i,n,data_element;
	cout<<"Enter the number of nodes : ";
	cin>>n;
	begin=NULL;
	if(n==0)
		return begin;
	cout<<"Enter the element: ";
	cin>>data_element;
	begin=addtoemptylist(begin,data_element);

	for(i=2;i<=n;i++)
	{
		cout<<"Enter the element to be inserted : ";
		cin>>data_element;
		begin=addatendlist(begin,data_element);
	}
	return begin;
}

void display(struct node *begin)
{
	struct node *p;
	if(begin==NULL)
	{
		cout<<"List is empty\n";
		return;
	}
	p=begin;
	cout<<"List is :\n";
	while(p!=NULL)
	{
		cout<<p->info<<" ";
		p=p->next_node;
	}
	cout<<"\n";
}

struct node *addtoemptylist(struct node *begin,int data_element)
{
	struct node *temp;
	temp=new struct node;
	temp->info=data_element;
	temp->prev_node=NULL;
	temp->next_node=NULL;
	begin=temp;
	return begin;
}
struct node *addatbeglist(struct node *begin,int data_element)
{
	if(begin==NULL)
	{
		cout<<"List is empty\n";
		return begin;
	}

	struct node *temp;
	temp = new struct node;
	temp->info=data_element;
	temp->prev_node=NULL;
	temp->next_node=begin;
	begin->prev_node=temp;
	begin=temp;
	return begin;
}

struct node *addatendlist(struct node *begin,int data_element)
{
	if(begin==NULL)
	{
		cout<<"List is empty\n";
		return begin;
	}

	struct node *temp,*p;
	temp=new struct node;
	temp->info=data_element;
	p=begin;
	while(p->next_node!=NULL)
		p=p->next_node;
	p->next_node=temp;
	temp->next_node=NULL;
	temp->prev_node=p;
	return begin;
}
struct node *addafterlist(struct node *begin,int data_element,int item_pos)
{
	struct node *temp,*p;
	temp=new struct node;
	temp->info=data_element;
	p=begin;
	while(p!=NULL)
	{
		if(p->info==item_pos)
		{
			temp->prev_node=p;
			temp->next_node=p->next_node;
			if(p->next_node!=NULL)
				p->next_node->prev_node=temp;
			p->next_node=temp;
			return begin;
		}
		p=p->next_node;
	}
	cout<<item_pos<<" not present in the list\n\n";
	return begin;
}

struct node *addbeforelist(struct node *begin,int data_element,int item_pos)
{
	struct node *temp,*q;
	if(begin==NULL )
	{
		cout<<"List is empty\n";
		return begin;
	}
	if(begin->info==item_pos)
	{
		temp = new struct node;
		temp->info=data_element;
		temp->prev_node=NULL;
		temp->next_node=begin;
		begin->prev_node=temp;
		begin=temp;
		return begin;
	}
	q=begin;
	while(q!=NULL)
	{
		if(q->info==item_pos)
		{
			temp=new struct node;
			temp->info=data_element;
			temp->prev_node=q->prev_node;
			temp->next_node = q;
			q->prev_node->next_node=temp;
			q->prev_node=temp;
			return begin;
		}
		q=q->next_node;
	}
	cout<<item_pos<<" not present in the list\n";
	return begin;
}

struct node *deletenode(struct node *begin,int data_element)
{
	struct node *temp;
	if(begin==NULL)
	{
		cout<<"List is empty\n";
		return begin;
	}
	if(begin->next_node==NULL)
		if(begin->info==data_element)
		{
			temp=begin;
			begin=NULL;
			delete(temp);
			return begin;
		}
		else
		{
			cout<<"Element "<<data_element<<" not found\n";
			return begin;
		}

	if(begin->info==data_element)
	{
		temp=begin;
		begin=begin->next_node;
		begin->prev_node=NULL;
		delete(temp);
		return begin;
	}

	temp=begin->next_node;
	while(temp->next_node!=NULL )
	{
		if(temp->info==data_element)
		{
			temp->prev_node->next_node=temp->next_node;
			temp->next_node->prev_node=temp->prev_node;
			delete(temp);
			return begin;
		}
		temp=temp->next_node;
	}

	if(temp->info==data_element)
	{
		temp->prev_node->next_node=NULL;
		delete(temp);
		return begin;
	}
	cout<<"Element "<<data_element<<" not found\n";
	return begin;
}

struct node *reverselist(struct node *begin)
{
	if(begin==NULL)
	{
		cout<<"List is empty\n";
		return begin;
	}

	struct node *p1,*p2;
	p1=begin;
	p2=p1->next_node;
	p1->next_node=NULL;
	p1->prev_node=p2;
	while(p2!=NULL)
	{
		p2->prev_node=p2->next_node;
		p2->next_node=p1;
		p1=p2;
		p2=p2->prev_node;
	}
	begin=p1;
	cout<<"List reverselistd\n";
	return begin;
