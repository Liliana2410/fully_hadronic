#!/bin/bash
ls
expect -f expect.expect

mv resultados.root bkg2.root

ls
sed -i 's/ttbartautau/nuevo/g' expect.expect
sed -i 's/Zprime_tautau_1000/viejo/g' expect.expect
sed -i 's/nuevo/ttbarh_hadronic/g' expect.expect
sed -i 's/viejo/ttbartautau/g' expect.expect

expect -f expect.expect

mv resultados.root bkg1.root

sed -i 's/ttbarh_hadronic/nuevo/g' expect.expect
sed -i 's/ttbartautau/viejo/g' expect.expect
sed -i 's/nuevo/Zprime_tautau_1000/g' expect.expect
sed -i 's/viejo/ttbarh_hadronic/g' expect.expect

expect -f expect.expect

mv resultados.root signal1.root

root plots.cxx << EOF
.q
EOF
ls

sed -i 's/ttbarh_hadronic/viejo/g' expect.expect
sed -i 's/Zprime_tautau_1000/nuevo/g' expect.expect
sed -i 's/nuevo/ttbartautau/g' expect.expect
sed -i 's/viejo/Zprime_tautau_1000/g' expect.expect
#**************************************************************
