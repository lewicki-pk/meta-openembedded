SUMMARY = "Powerful and Pythonic XML processing library combining libxml2/libxslt with the ElementTree API."
DESCRIPTION = "lxml is a Pythonic, mature binding for the libxml2 and \
libxslt libraries. It provides safe and convenient access to these \
libraries using the ElementTree API. It extends the ElementTree API \
significantly to offer support for XPath, RelaxNG, XML Schema, XSLT, \
C14N and much more."
HOMEPAGE = "http://codespeak.net/lxml"
SECTION = "devel/python"
LICENSE = "BSD & GPLv2 & MIT & PSF"
LIC_FILES_CHKSUM = "file://LICENSES.txt;md5=f9f1dc24f720c143c2240df41fe5073b \
                    file://doc/licenses/elementtree.txt;md5=eb34d036a6e3d56314ee49a6852ac891 \
                    file://doc/licenses/BSD.txt;md5=700a1fc17f4797d4f2d34970c8ee694b \
                    file://doc/licenses/GPL.txt;md5=94d55d512a9ba36caa9b7df079bae19f \
                    file://src/lxml/isoschematron/resources/rng/iso-schematron.rng;startline=2;endline=7;md5=a2914d12acc7066b3f5b60e8f94a012e \
                    file://src/lxml/isoschematron/resources/xsl/iso-schematron-xslt1/iso_schematron_message.xsl;startline=2;endline=24;md5=96976dcc66249c51e8026b159ca5e755 \
                    file://src/lxml/isoschematron/resources/xsl/RNG2Schtrn.xsl;startline=2;endline=7;md5=5cac4ad4b5e131a10e9af755b10fbbb7 \
                    "

DEPENDS += "libxml2 libxslt"

SRC_URI[md5sum] = "b78e6f7e859c2ff57add7f63a5e387b7"
SRC_URI[sha256sum] = "9c62eb2a1862e1ae285d7e7e3b7dc8772d387b19258086afcec143c6b7b8a5c9"

DISTUTILS_BUILD_ARGS += " \
                     --with-xslt-config='pkg-config libxslt' \
                     --with-xml2-config='pkg-config libxml-2.0' \
"

DISTUTILS_INSTALL_ARGS += " \
                     --with-xslt-config='pkg-config libxslt' \
                     --with-xml2-config='pkg-config libxml-2.0' \
"

inherit pypi

do_configure_prepend() {
    sed -i -e 's/--version/--modversion/' ${B}/setupinfo.py
}

BBCLASSEXTEND = "native nativesdk"

RDEPENDS_${PN} += "libxml2 libxslt ${PYTHON_PN}-compression"
RDEPENDS_${PN}_class-native = "libxml2-native libxslt-native"
