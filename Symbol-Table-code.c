#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;alloc.h&gt;
#include&lt;string.h&gt;
#include&lt;stdlib.h&gt;
#define NULL 0
int size=0;
void Insert();
void Display();
void Delete();
int Search(char lab[]);
void Modify();
struct SymbTab
{
char label[10],symbol[10];
int addr;
struct SymbTab *next;
};
struct SymbTab *first,*last;
void main()
{
int op,y;
char la[10];
clrscr();
do
{
printf(&quot;\n\tSYMBOL TABLE IMPLEMENTATION\n&quot;);
printf(&quot;\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n&quot;);
printf(&quot;\n\tEnter your option : &quot;);
scanf(&quot;%d&quot;,&amp;op);
switch(op)
{
case 1:
Insert();
break;
case 2:
Display();
break;
case 3:
Delete();
break;
case 4:
printf(&quot;\n\tEnter the label to be searched : &quot;);
scanf(&quot;%s&quot;,la);
y=Search(la);
printf(&quot;\n\tSearch Result:&quot;);
if(y==1)
printf(&quot;\n\tThe label is present in the symbol table\n&quot;);
else
printf(&quot;\n\tThe label is not present in the symbol table\n&quot;);
break;
case 5:
Modify();
break;
case 6:
exit(0);
}
}while(op&lt;6);
getch();
}
void Insert()
{
int n;
char l[10];
printf(&quot;\n\tEnter the label : &quot;);
scanf(&quot;%s&quot;,l);
n=Search(l);
if(n==1)
printf(&quot;\n\tThe label exists already in the symbol table\n\tDuplicate can&#39;t be inserted&quot;);
else
{
struct SymbTab *p;
p=malloc(sizeof(struct SymbTab));
strcpy(p-&gt;label,l);
printf(&quot;\n\tEnter the symbol : &quot;);
scanf(&quot;%s&quot;,p-&gt;symbol);
printf(&quot;\n\tEnter the address : &quot;);
scanf(&quot;%d&quot;,&amp;p-&gt;addr);
p-&gt;next=NULL;
if(size==0)
{
first=p;
last=p;
}
else
{
last-&gt;next=p;
last=p;
}
size++;
}
printf(&quot;\n\tLabel inserted\n&quot;);
}
void Display()
{
int i;
struct SymbTab *p;
p=first;
printf(&quot;\n\tLABEL\t\tSYMBOL\t\tADDRESS\n&quot;);
for(i=0;i&lt;size;i++)
{
printf(&quot;\t%s\t\t%s\t\t%d\n&quot;,p-&gt;label,p-&gt;symbol,p-&gt;addr);
p=p-&gt;next;
}
}
int Search(char lab[])
{
int i,flag=0;
struct SymbTab *p;
p=first;
for(i=0;i&lt;size;i++)
{
if(strcmp(p-&gt;label,lab)==0)
flag=1;
p=p-&gt;next;
}
return flag;
}
void Modify()
{
char l[10],nl[10];
int add,choice,i,s;
struct SymbTab *p;
p=first;
printf(&quot;\n\tWhat do you want to modify?\n&quot;);
printf(&quot;\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n&quot;);
printf(&quot;\tEnter your choice : &quot;);
scanf(&quot;%d&quot;,&amp;choice);
switch(choice)
{
case 1:
printf(&quot;\n\tEnter the old label : &quot;);
scanf(&quot;%s&quot;,l);
s=Search(l);
if(s==0)
printf(&quot;\n\tLabel not found\n&quot;);
else
{
printf(&quot;\n\tEnter the new label : &quot;);
scanf(&quot;%s&quot;,nl);
for(i=0;i&lt;size;i++)
{
if(strcmp(p-&gt;label,l)==0)
strcpy(p-&gt;label,nl);
p=p-&gt;next;
}
printf(&quot;\n\tAfter Modification:\n&quot;);
Display();
}
break;
case 2:
printf(&quot;\n\tEnter the label where the address is to be modified : &quot;);
scanf(&quot;%s&quot;,l);
s=Search(l);
if(s==0)
printf(&quot;\n\tLabel not found\n&quot;);
else
{
printf(&quot;\n\tEnter the new address : &quot;);
scanf(&quot;%d&quot;,&amp;add);
for(i=0;i&lt;size;i++)
{
if(strcmp(p-&gt;label,l)==0)
p-&gt;addr=add;
p=p-&gt;next;
}
printf(&quot;\n\tAfter Modification:\n&quot;);
Display();
}
break;
case 3:
printf(&quot;\n\tEnter the old label : &quot;);
scanf(&quot;%s&quot;,l);
s=Search(l);
if(s==0)
printf(&quot;\n\tLabel not found\n&quot;);
else
{
printf(&quot;\n\tEnter the new label : &quot;);
scanf(&quot;%s&quot;,nl);
printf(&quot;\n\tEnter the new address : &quot;);
scanf(&quot;%d&quot;,&amp;add);
for(i=0;i&lt;size;i++)
{
if(strcmp(p-&gt;label,l)==0)
{
strcpy(p-&gt;label,nl);
p-&gt;addr=add;
}
p=p-&gt;next;
}
printf(&quot;\n\tAfter Modification:\n&quot;);
Display();
}
break;
}
}
void Delete()
{
int a;
char l[10];
struct SymbTab *p,*q;
p=first;
printf(&quot;\n\tEnter the label to be deleted : &quot;);
scanf(&quot;%s&quot;,l);
a=Search(l);
if(a==0)
printf(&quot;\n\tLabel not found\n&quot;);
else
{
if(strcmp(first-&gt;label,l)==0)
first=first-&gt;next;
else if(strcmp(last-&gt;label,l)==0)
{
q=p-&gt;next;
while(strcmp(q-&gt;label,l)!=0)
{
p=p-&gt;next;
q=q-&gt;next;
}
p-&gt;next=NULL;
last=p;
}
else
{
q=p-&gt;next;
while(strcmp(q-&gt;label,l)!=0)
{
p=p-&gt;next;
q=q-&gt;next;
}
p-&gt;next=q-&gt;next;
}
size--;
printf(&quot;\n\tAfter Deletion:\n&quot;);
Display();
}
}
