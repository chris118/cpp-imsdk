# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.demo.Debug:
PostBuild.privchat.Debug: /Users/admin/putao_ios/privchat/imsdk/ios-build/Debug${EFFECTIVE_PLATFORM_NAME}/demo
/Users/admin/putao_ios/privchat/imsdk/ios-build/Debug${EFFECTIVE_PLATFORM_NAME}/demo:\
	/Users/admin/putao_ios/privchat/imsdk/ios-build/Debug${EFFECTIVE_PLATFORM_NAME}/libprivchat.a
	/bin/rm -f /Users/admin/putao_ios/privchat/imsdk/ios-build/Debug${EFFECTIVE_PLATFORM_NAME}/demo


PostBuild.privchat.Debug:
/Users/admin/putao_ios/privchat/imsdk/ios-build/Debug${EFFECTIVE_PLATFORM_NAME}/libprivchat.a:
	/bin/rm -f /Users/admin/putao_ios/privchat/imsdk/ios-build/Debug${EFFECTIVE_PLATFORM_NAME}/libprivchat.a


PostBuild.demo.Release:
PostBuild.privchat.Release: /Users/admin/putao_ios/privchat/imsdk/ios-build/Release${EFFECTIVE_PLATFORM_NAME}/demo
/Users/admin/putao_ios/privchat/imsdk/ios-build/Release${EFFECTIVE_PLATFORM_NAME}/demo:\
	/Users/admin/putao_ios/privchat/imsdk/ios-build/Release${EFFECTIVE_PLATFORM_NAME}/libprivchat.a
	/bin/rm -f /Users/admin/putao_ios/privchat/imsdk/ios-build/Release${EFFECTIVE_PLATFORM_NAME}/demo


PostBuild.privchat.Release:
/Users/admin/putao_ios/privchat/imsdk/ios-build/Release${EFFECTIVE_PLATFORM_NAME}/libprivchat.a:
	/bin/rm -f /Users/admin/putao_ios/privchat/imsdk/ios-build/Release${EFFECTIVE_PLATFORM_NAME}/libprivchat.a


PostBuild.demo.MinSizeRel:
PostBuild.privchat.MinSizeRel: /Users/admin/putao_ios/privchat/imsdk/ios-build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/demo
/Users/admin/putao_ios/privchat/imsdk/ios-build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/demo:\
	/Users/admin/putao_ios/privchat/imsdk/ios-build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libprivchat.a
	/bin/rm -f /Users/admin/putao_ios/privchat/imsdk/ios-build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/demo


PostBuild.privchat.MinSizeRel:
/Users/admin/putao_ios/privchat/imsdk/ios-build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libprivchat.a:
	/bin/rm -f /Users/admin/putao_ios/privchat/imsdk/ios-build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libprivchat.a


PostBuild.demo.RelWithDebInfo:
PostBuild.privchat.RelWithDebInfo: /Users/admin/putao_ios/privchat/imsdk/ios-build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/demo
/Users/admin/putao_ios/privchat/imsdk/ios-build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/demo:\
	/Users/admin/putao_ios/privchat/imsdk/ios-build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libprivchat.a
	/bin/rm -f /Users/admin/putao_ios/privchat/imsdk/ios-build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/demo


PostBuild.privchat.RelWithDebInfo:
/Users/admin/putao_ios/privchat/imsdk/ios-build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libprivchat.a:
	/bin/rm -f /Users/admin/putao_ios/privchat/imsdk/ios-build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libprivchat.a




# For each target create a dummy ruleso the target does not have to exist
/Users/admin/putao_ios/privchat/imsdk/ios-build/Debug${EFFECTIVE_PLATFORM_NAME}/libprivchat.a:
/Users/admin/putao_ios/privchat/imsdk/ios-build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libprivchat.a:
/Users/admin/putao_ios/privchat/imsdk/ios-build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libprivchat.a:
/Users/admin/putao_ios/privchat/imsdk/ios-build/Release${EFFECTIVE_PLATFORM_NAME}/libprivchat.a:
