.name "name"
.comment "comment"

deb:	ldi		%0, %0, r0
		sti		r0, %:deb, %1
live:	live	%1
		zjmp	%:live
