debug ?= 1 #isključiti dodavanjem debug=0 pri make-u, npr. $ make debug=0 run

CFLAGS = -MMD -D DEBUG=$(debug)
LDFLAGS = -O3
LDLIBS =


OBJEKTI = dublje.o
MODUL = mod-dublje.o
ZAGLAVLJA=$(OBJEKTI:.o=.d)

$(MODUL): $(OBJEKTI)
	$(LD) -r $^ $(LDFLAGS) -o $@

dublje.o: dublje.c dublje.h $(POCETNI_DIREKTORIJ)/postavke.h
	$(CC) $(CFLAGS) -o $@ -c $<

# brisanje
.PHONY: brisi
brisi:
	rm -f $(ZAGLAVLJA) $(OBJEKTI) $(MODUL)
	
-include $(ZAGLAVLJA)
