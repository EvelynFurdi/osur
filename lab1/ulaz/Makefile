debug ?= 1 #isključiti dodavanjem debug=0 pri make-u, npr. $ make debug=0 run

CFLAGS = -MMD -D DEBUG=$(debug)
LDFLAGS = -O3
LDLIBS =

OBJEKTI = ulaz.o
MODULI = datoteka/mod-datoteka.o 
MODUL = mod-ulaz.o
ZAGLAVLJA=$(OBJEKTI:.o=.d)

$(MODUL): $(OBJEKTI) $(MODULI)
	$(LD) -r $^ $(LDFLAGS) -o $@ 

ulaz.o: ulaz.c ulaz.h $(POCETNI_DIREKTORIJ)/postavke.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: $(MODULI)
$(MODULI):
	$(MAKE) -C $(dir $@)

# brisanje
.PHONY: brisi
brisi:
	$(MAKE) -C datoteka brisi
	rm -f $(ZAGLAVLJA) $(OBJEKTI) $(MODUL)

-include $(ZAGLAVLJA)
