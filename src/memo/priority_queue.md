|   | push | pop | modify | erase |
| --- | --- | --- | --- | --- |
| std::priority_queue | 最悪$\Theta(n)$,償却$\Theta(\log(n))$ | 最悪$\Theta(\log(n))$ | 最悪$\Theta(n\log(n))$ | $\Theta(n \log(n))$ |
| pairing_heap_tag | $O(1)$ | 最悪$\Theta(n)$, 償却$\Theta(\log n)$ | 最悪$\Theta(n)$, 償却$\Theta(\log(n))$ | 最悪$\Theta(n)$, 償却$O(\log(n))$ |
| binary_heap_tag | 最悪$\Theta(n)$, 償却$O(\log(n))$ | 最悪$\Theta(n)$, 償却$O(\log(n))$ | $\Theta(n)$ | $\Theta(n)$ |
| binomial_heap_tag | 最悪$\Theta(n)$, 償却$O(\log(n))$  | $\Theta(\log (n))$ | $\Theta(\log(n)) $ | $\Theta(\log(n))$ | 
|rc_binomial_heap_tag | $O(1)$ | $\Theta(\log(n))$ | $\Theta(\log(n))$  | $\Theta(\log(n))$ | 
|thin_heap_tag | $O(1)$ | 最悪$\Theta(n)$, 償却$O(\log(n))$  | 最悪$\Theta(\log(n))$,償却$O(1)$ or 償却$\Theta(\log n)$ | 最悪$\Theta(n)$, 償却$O(\log(n))$ | 

joinは基本的にeraseの最悪計算量に一致.pairing_heap_tagのみ高速で$O(1)$