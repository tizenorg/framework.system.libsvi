Name:       libfeedback
Summary:    Feedback library
Version:    0.1.3
Release:    1
Group:      System/Libraries
License:    Apache License, Version 2.0
Source0:    %{name}-%{version}.tar.gz
Source1:	libsvi.manifest
source2:	libfeedback.manifest
source3:	svi-data.manifest
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  cmake
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(vconf)
BuildRequires:  pkgconfig(mm-keysound)
%if "%{_repository}" == "wearable"
BuildRequires:  pkgconfig(dbus-1)
%else
BuildRequires:  pkgconfig(haptic)
%endif
BuildRequires:  pkgconfig(libxml-2.0)
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(capi-base-common)
Requires(post):	svi-data

%description
Feedback library for playing sound, vibration and led


%package -n libfeedback-devel
Summary:    Feedback library for (devel)
Group:      Development/Libraries
Requires:   libfeedback = %{version}-%{release}

%description -n libfeedback-devel
Feedback library for playing sound, vibration and led (devel)

%package -n libsvi
Summary:	SVI library
Group:		Development/Libraries
Requires:	libfeedback = %{version}-%{release}

%description -n libsvi
SVI library

%package -n libsvi-devel
Summary:	SVI library for (devel)
Group:		Development/Libraries
Requires:	libsvi = %{version}-%{release}

%description -n libsvi-devel
SVI library (devel)

%package -n svi-data
Summary: 	svi resource package
Group:		Development/Libraries
Requires(post):	smack-utils

%description -n svi-data
svi resource package

%prep
%setup -q

%build
%if 0%{?tizen_build_binary_release_type_eng}
export CFLAGS+=" -DTIZEN_ENGINEER_MODE"
%endif
cp %{SOURCE1} .
cp %{SOURCE2} .
cp %{SOURCE3} .

%if "%{_repository}" == "wearable"
%define DEVICE wearable
%else
%define DEVICE mobile
%endif

cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix} -DDEVICE=%{DEVICE}
make

%install
rm -rf %{buildroot}
%make_install

mkdir -p %{buildroot}%{_datadir}/license
cp LICENSE %{buildroot}/usr/share/license/%{name}
cp LICENSE %{buildroot}/usr/share/license/svi-data
cp LICENSE %{buildroot}/usr/share/license/libsvi

mkdir -p %{buildroot}/opt/usr/share/feedback/haptic/custom

%post -p /sbin/ldconfig

%post -n svi-data

if [ -f %{_libdir}/rpm-plugins/msm.so ]; then
	find /opt/usr/share/feedback/ | xargs chsmack -a 'svi-data'
fi

%postun -p /sbin/ldconfig

%postun -n svi-data
rm -rf %{_datadir}/feedback/
rm -rf /opt/usr/share/feedback/

%files
%defattr(-,root,root,-)
%{_libdir}/libfeedback.so.*
%{_datadir}/license/%{name}
%manifest libfeedback.manifest

%files -n libfeedback-devel
%defattr(-,root,root,-)
%{_includedir}/feedback/*.h
%{_libdir}/libfeedback.so
%{_libdir}/pkgconfig/feedback.pc

%files -n libsvi
%defattr(-,root,root,-)
%{_libdir}/libsvi.so.*
%{_datadir}/license/libsvi
%manifest libsvi.manifest

%files -n libsvi-devel
%defattr(-,root,root-)
%{_includedir}/svi/*.h
%{_libdir}/libsvi.so
%{_libdir}/pkgconfig/svi.pc

%files -n svi-data
%defattr(644,root,root,-)
%{_datadir}/feedback/*
%defattr(666,app,app,-)
%dir /opt/usr/share/feedback/haptic/custom
%{_datadir}/license/svi-data
%manifest svi-data.manifest
