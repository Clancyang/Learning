转载于博客，[点击访问原文](https://www.cnblogs.com/code-painter/p/4417354.html)
## 关于卡特兰数
> 卡特兰数是一种经典的组合数，经常出现在各种计算中，其前几项为 : 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452, ...

## 卡特兰数的一般公式
> 卡特兰数满足以下性质：<br/>

令h(0)=1,h(1)=1，catalan数满足递推式。
    h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)*h(0) (n>=2)。
也就是说，如果能把公式化成上面这种形式的数，就是卡特兰数。

这个公式还可以更简单得化为
    h(n)=C(2n,n)/(n+1)。 
      
## 卡特兰数的应用
> 卡特兰数经常出现在OI以及ACM中，在生活中也有广泛的应用。下面举几个例子。
### 出栈次序：一个栈（无穷大）的进栈次序为1、2、3……n。不同的出栈次序有几种。
> 我们可以这样想，假设k是最后一个出栈的数。比k早进栈且早出栈的有k-1个数，一共有h(k-1)种方案。比k晚进栈且早出栈的有n-k个数，一共有h(n-k)种方案。所以一共有h(k-1)*h(n-k)种方案。显而易见，k取不同值时，产生的出栈序列是相互独立的，所以结果可以累加。k的取值范围为1至n，所以结果就为h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0)。<br/>
> 出栈入栈问题有许多的变种，比如n个人拿5元、n个人拿10元买物品，物品5元，老板没零钱。问有几种排队方式。熟悉栈的同学很容易就能把这个问题转换为栈。值得注意的是，由于每个拿5元的人排队的次序不是固定的，所以最后求得的答案要*n!。拿10元的人同理，所以还要*n!。所以这种变种的最后答案为h(n)*n!*n!。
       
### 二叉树构成问题。有n个结点，问总共能构成几种不同的二叉树。
> 我们可以假设，如果采用中序遍历的话，根结点第k个被访问到，则根结点的左子树有k-1个点、根结点的右指数有n-k个点。k的取值范围为1到n。讲到这里就很明显看得出是卡特兰数了。这道题出现在2015年腾讯实习生的在线笔试题中。有参加过的同学想必都有印象。
  
### 凸多边形的三角形划分。一个凸的n边形，用直线连接他的两个顶点使之分成多个三角形，每条直线不能相交，问一共有多少种划分方案。
> 这也是非常经典的一道题。我们可以这样来看，选择一个基边，显然这是多边形划分完之后某个三角形的一条边。图中我们假设基边是p1pn，我们就可以用p1、pn和另外一个点假设为pi做一个三角形，并将多边形分成三部分，除了中间的三角形之外，一边是i边形，另一边是n-i+1边形。i的取值范围是2到n-1。所以本题的解c(n)=c(2)*c(n-1)+c(3)*c(n-2)+...c(n-1)*c(2)。令t(i)=c(i+2)。则t(i)=t(0)*t(i-1)+t(1)*t(i-2)...+t(i-1)*t(0)。很明显，这就是一个卡特兰数了。