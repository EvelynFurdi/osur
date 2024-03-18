POCETNI_DIREKTORIJ = $(shell pwd)
export POCETNI_DIREKTORIJ


debug ?= 1 #isključiti dodavanjem debug=0 pri make-u, npr. $ make debug=0 run

CFLAGS = -MMD -D DEBUG=$(debug)
LDFLAGS = -O3
LDLIBS =

all: $(PROGRAM)

OBJEKTI = main.o
MODULI =  ulaz/mod-ulaz.o obrada/mod-obrada.o izlaz/mod-izlaz.o
ZAGLAVLJA=$(OBJEKTI:.o=.d)

main.o: main.c $(POCETNI_DIREKTORIJ)/postavke.h
	$(CC) $(CFLAGS) -o $@ -c $<

PROGRAM=lab1

$(PROGRAM): $(OBJEKTI) $(MODULI)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@


.PHONY: $(MODULI)
$(MODULI):
	$(MAKE) -C $(dir $@)

# brisanje
.PHONY: brisi
brisi:
	$(MAKE) -C ulaz brisi
	$(MAKE) -C obrada brisi
	$(MAKE) -C izlaz brisi
	rm -f $(ZAGLAVLJA) $(OBJEKTI) $(PROGRAM)

.PHONY: pokreni
pokreni: $(PROGRAM)
	./$(PROGRAM)
	
-include $(ZAGLAVLJA)
