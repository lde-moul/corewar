.name "name"
.comment "comment"

deb2:
deb1:
		ld		%50, r17
		st		r2, 50
deb:	ldi		%0, %0, r0
		sti		r1, %8, %0
live:	live	%0
		zjmp	%:deb2
