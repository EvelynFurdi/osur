debug ?= 1 #isključiti dodavanjem debug=0 pri make-u, npr. $ make debug=0 run

CFLAGS = -MMD -D DEBUG=$(debug)
LDFLAGS = -O3
LDLIBS =

OBJEKTI = obrada.o
MODULI = pobroji/mod-pobroji.o smisao/mod-smisao.o
MODUL = mod-obrada.o
ZAGLAVLJA=$(OBJEKTI:.o=.d)

$(MODUL): $(OBJEKTI) $(MODULI)
	$(LD) -r $^ $(LDFLAGS) -o $@ 

obrada.o: obrada.c obrada.h $(POCETNI_DIREKTORIJ)/postavke.h
	$(CC) $(CFLAGS) -o $@ -c $<
	
.PHONY: $(MODULI)
$(MODULI):
	$(MAKE) -C $(dir $@)

# brisanje
.PHONY: brisi
brisi:
	$(MAKE) -C pobroji brisi
	$(MAKE) -C smisao brisi
	rm -f $(ZAGLAVLJA) $(OBJEKTI) $(MODUL)
	
-include $(ZAGLAVLJA)	


