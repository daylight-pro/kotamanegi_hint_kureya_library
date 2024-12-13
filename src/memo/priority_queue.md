|   | push | pop | modify | erase | join | 
| --- | --- | --- | --- | --- | --- |
| std::priority_queue | 最悪$\Theta(n)$,償却$\Theta(\log(n))$ | 最悪$\Theta(\log(n))$ | 最悪$\Theta(n\log(n))$ | $\Theta(n \log(n))$ | $\Theta(n \log (n))$|
| priority_queue<pairing_heap_tag> | $O(1)$ | 最悪$\Theta(n)$, 償却$\Theta(\log n)$ | 最悪$\Theta(n)$, 償却$\Theta(\log(n))$ | 最悪$\Theta(n)$, 償却$O(\log(n))$ | O(1) |
| priority_queue<binary_heap_tag> | 最悪$\Theta(n)$, 償却$O(\log(n))$ | 最悪$\Theta(n)$, 償却$O(\log(n))$ | $\Theta(n)$ | $\Theta(n)$ | $\Theta(n)$ |
| priority_queue<binomial_heap_tag> | 最悪$\Theta(n)$, 償却$O(\log(n))$  | $\Theta(\log (n))$ | $\Theta(\log(n)) $ | $\Theta(\log(n))$ | $\Theta(\log(n))$ |
|priority_queue<rc_binomial_heap_tag> | $O(1)$ | $\Theta(\log(n))$ | $\Theta(\log(n))$  | $\Theta(\log(n))$ | $\Theta(\log(n))$ |
|priority_queue<thin_heap_tag> | $O(1)$ | 最悪$\Theta(n)$, 償却$O(\log(n))$  | 最悪$\Theta(\log(n))$,償却$O(1)$ or 償却$\Theta(\log n)$ | 最悪$\Theta(n)$, 償却$O(\log(n))$ | $\Theta(n)$

