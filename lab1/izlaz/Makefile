debug ?= 1 #isključiti dodavanjem debug=0 pri make-u, npr. $ make debug=0 run

CFLAGS = -MMD -D DEBUG=$(debug)
LDFLAGS = -O3
LDLIBS =

OBJEKTI = izlaz.o
MODULI = datoteka/mod-datoteka.o ispis/mod-ispis.o
MODUL = mod-izlaz.o
ZAGLAVLJA=$(OBJEKTI:.o=.d)

$(MODUL): $(OBJEKTI) $(MODULI)
	$(LD) -r $^ $(LDFLAGS) -o $@ 

izlaz.o: izlaz.c izlaz.h $(POCETNI_DIREKTORIJ)/postavke.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: $(MODULI)
$(MODULI):
	$(MAKE) -C $(dir $@)

# brisanje
.PHONY: brisi
brisi:
	$(MAKE) -C datoteka brisi
	$(MAKE) -C ispis brisi
	rm -f $(ZAGLAVLJA) $(OBJEKTI) $(MODUL)
	
-include $(ZAGLAVLJA)
