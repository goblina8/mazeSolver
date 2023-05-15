NAZWA_APLIKACJI=MazeSolver
NAZWA_KATALOGU=Inżynierka

URUCHOMIENIE_APLIKACJI=./${NAZWA_APLIKACJI}

ZRODLA_PROJEKTU=`/bin/pwd`/ui/*.ui `/bin/pwd`/src/*.cpp `/bin/pwd`/inc/*.hh\
                 `/bin/pwd`/inc/*.hpp `/bin/pwd`/res/*.qrc

PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ}\
             UI_DIR=${KATALOG_ROBOCZY}/out/ui\
             INCLUDEPATH=inc\
             INCLUDEPATH+=./\
             MOC_DIR=${KATALOG_MOC}\
             RCC_DIR=${KATALOG_RCC}\
			 QT+=core gui\
             QT+=widgets\
                          QMAKE_CXXFLAGS+=-std=c++11\
             QMAKE_RESOURCE_FLAGS=-no-compress

KATALOG_ROBOCZY=/tmp/${NAZWA_KATALOGU}
KATALOG_OBJ=${KATALOG_ROBOCZY}/out/obj
KATALOG_MOC=${KATALOG_ROBOCZY}/out/moc
KATALOG_RCC=${KATALOG_ROBOCZY}/out/rcc
KATALOG_PRO=${KATALOG_ROBOCZY}/pro
KATALOG_MAKE=.


__start__: __sprawdz_Qt__ ${NAZWA_APLIKACJI}
	@echo
	@echo "             Praca Inżynierska  "
	@echo "    Planowanie ruchu robota w labiryntach"
	@echo "            Gabriela Kaczmarek  "
	@echo 
	rm -f core*; ${URUCHOMIENIE_APLIKACJI}

__sprawdz_Qt__: __sprawdz_qmake__
	@if qmake -v | grep 'ver.*5\.[0-9]*\.[0-9]*' > /dev/null;\
         then exit 0;\
         else echo; echo " Brak biblioteki Qt w wersji 5.x.x";\
              echo;  exit 1;\
        fi

__sprawdz_qmake__:
	@if which qmake > /dev/null; then exit 0;\
        else\
          echo; echo " Brak programu qmake."\
               " Prawdopodobnie biblioteka Qt nie zostala zainstalowana.";\
          echo; exit 1;\
        fi


${NAZWA_APLIKACJI}: ${KATALOG_MAKE}/Makefile.app __sprawdz__

__sprawdz__:
	make -f ${KATALOG_MAKE}/Makefile.app

${KATALOG_MAKE}/Makefile.app: ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro
	qmake -o ${KATALOG_MAKE}/Makefile.app ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro: Makefile
	rm -fr ${KATALOG_PRO}/
	qmake -project -o ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro\
               ${PODSTAWIENIA} ${ZRODLA_PROJEKTU} 

project: __usun_pro__ ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

__usun_pro__:
	rm -f ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

clean:
	make -f ${KATALOG_MAKE}/Makefile.app clean

cleanall: clean
	rm -f ${NAZWA_APLIKACJI}

__clean_auxiliary_files__:
	find . -name \*~ -exec rm {} \;
	find . -name \*.tex -exec rm {} \;

cleantotally: __clean_auxiliary_files__ cleanall
	rm -f  ${KATALOG_MAKE}/Makefile.app .qmake.stash
	rm -fr ${KATALOG_MOC} ${KATALOG_OBJ}
	rm -rf ${KATALOG_PRO}/

help:
	@echo "Podcele:"
	@echo 
	@echo " project  - wymusza utworzenie nowego projektu"
	@echo " clean    - usuwa wszystkie produkty kompilacji i konsolidacji"
	@echo " cleanall - usuwa produkty kompilacji wraz z aplikacja"
	@echo " cleantotally - usuwa wszystko oprocz zrodel i pliku Makefile"
	@echo " help     - wyswietla niniejszy pomoc"
	@echo
