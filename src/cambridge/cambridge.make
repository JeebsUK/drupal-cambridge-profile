api = 2
core = 7.x

includes[cambridge_base] = "../cambridge_base.make"

; contrib

projects[admin_menu] = "3.0-rc6"
projects[admin_views] = "1.6"
projects[advanced_help] = "1.5"
projects[auto_entitylabel] = "1.4"
projects[better_formats] = "1.0-beta2"
projects[bigmenu] = "1.3"
projects[block_titlelink] = "1.5"
projects[calendar] = "3.5"
projects[ckeditor] = "1.18"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.7/ckeditor_4.4.7_full.tar.gz"
projects[ckeditor_link] = "2.4"
projects[context] = "3.10"
projects[crazyegg] = "1.1"
projects[css_injector] = "1.10"
projects[date] = "2.10"
projects[default_menu_link] = "1.3"
projects[delta] = "3.0-beta11"
projects[devel] = "1.7"
projects[diff] = "3.4"
projects[disqus] = "1.12"
projects[ds] = "2.16"
projects[easy_breadcrumb] = "2.16"
projects[email] = "1.3"
projects[entity] = "1.9"
projects[entityreference] = "1.5"
projects[environment_indicator][version] = "2.9"
projects[environment_indicator][patch][] = "http://www.drupal.org/files/issues/z-index-2331315-1.patch"
projects[expire][version] = "1.0-beta1"
projects[expire][patch][] = "http://cgit.drupalcode.org/expire/patch/?id=c0e37cc"
projects[facetapi] = "1.5"
projects[facetapi_pretty_paths] = "1.4"
projects[fancybox][version] = "2.0-beta6"
projects[fancybox][patch][] = "https://gist.githubusercontent.com/thewilkybarkid/6550012/raw/23071cf776df3e61ba823f6c73bb788316778945/fancybox_jquery.patch"
libraries[fancybox][download][type] = "file"
libraries[fancybox][download][url] = "https://github.com/fancyapps/fancyBox/archive/v2.1.5.tar.gz"
projects[features_extra] = "1.0"
projects[feeds][version] = "2.0-beta3"
#projects[feeds][patch][] = "https://www.drupal.org/files/issues/feeds-cache-table-exists-2531706-1.patch" #should be fixed in new version
projects[feeds_entity_processor] = "1.x-dev"
projects[feeds_tamper] = "1.1"
projects[feeds_xpathparser] = "1.1"
projects[field_collection] = "1.0-beta13"
projects[field_display_label] = "1.4"
projects[field_group] = "1.6"
projects[field_permissions] = "1.0"
projects[field_validation] = "2.6"
projects[file_entity] = "2.25"
projects[file_resup] = "1.5"
projects[filefield_paths][version] = "1.1"
projects[fontawesome] = "3.8"
projects[filefield_sources] = "1.11"
projects[globalredirect] = "1.6"
projects[google_analytics] = "2.6"
projects[hierarchical_select] = "3.0-beta9"
projects[honeypot] = "1.25"
projects[image_link_formatter] = "1.1"
projects[imageapi_optimize] = "1.3"
projects[imagecache_external] = "2.2"
projects[job_scheduler] = "2.0"
projects[linkchecker] = "1.4"
projects[markup] = "1.2"
projects[media] = "2.21"
projects[media_ckeditor] = "2.9"
projects[media_flickr] = "2.0-alpha5"
projects[media_soundcloud] = "1.0"
projects[media_vimeo] = "2.1"
projects[media_youtube] = "3.8"
projects[memcache] = "1.6"
projects[menu_admin_per_menu] = "1.1"
projects[menu_force] = "1.2"
projects[menu_trail_by_path] = "3.3"
projects[menu_view_unpublished] = "1.0-beta3"
projects[metatag] = "1.25"
projects[migrate] = "2.11"
projects[migrate_extras] = "2.5"
projects[module_filter] = "2.2"
projects[multiselect] = "1.13"
projects[node_clone] = "1.0"
projects[nodequeue] = "2.1"
projects[oembed] = "1.0-rc2"
projects[paragraphs] = "1.0-rc5"
projects[pathologic] = "2.12"
projects[persistent_menu_items] = "1.0"
projects[publishcontent] = "1.4"
projects[realname] = "1.3"
projects[realname][patch][] = "https://www.drupal.org/files/issues/realname-fix-user-view-warning-2782711-4-D7.patch"
projects[redirect][version] = "1.0-rc3"
projects[restws] = "2.8"
projects[role_delegation] = "1.1"
projects[rules] = "2.12"
projects[scheduler] = "1.5"
projects[search_api] = "1.26"
projects[search_api_db] = "1.7"
projects[search_api_sorts] = "1.7"
projects[select_or_other] = "2.24"
projects[sharethis] = "2.13"
projects[similarterms][version] = "2.6"
#projects[similarterms][patch][] = "http://www.drupal.org/files/0001-similarterm-options-were-not-being-saved-due-to-wron.patch"
projects[smart_trim][version] = "1.5"
projects[smart_trim][patch][] = "http://drupal.org/files/issues/smart_trim_remove_punctuation_from_end_of_truncated_output-2169583-7.patch"
projects[stringoverrides] = "1.8"
projects[strongarm] = "2.0"
projects[synonyms] = "1.6"
projects[tac_lite] = "1.2"
projects[taxonomy_display] = "1.1"
projects[taxonomy_manager] = "1.0"
projects[taxonomy_menu] = "1.5"
projects[telephone] = "1.0-alpha1"
projects[term_merge] = "1.4"
projects[toc_node] = "1.7"
projects[transliteration] = "3.2"
projects[twitter_block] = "2.3"
projects[uuid] = "1.2"
projects[varnish] = "1.9"
;projects[varnish][version] = "1.0-beta3"
;projects[varnish][patch][] = "https://gist.github.com/thewilkybarkid/6595645/raw/e53554206350c1b00316fcf02f2ff61c0bdfee36/varnish_watchdog_success.patch"
;projects[varnish][patch][] = "https://gist.github.com/thewilkybarkid/6595676/raw/4ddb6a03ce521ab5520e27099997650a2e390679/varnish_authentication_fix.patch"
;projects[varnish][patch][] = "http://www.drupal.org/files/issues/varnish_purge_limit-1481136-11_1.patch"
;projects[varnish][patch][] = "https://gist.githubusercontent.com/thewilkybarkid/6595681/raw/b758ac37a72f0e1a16fd49a47383fedf54ace30c/varnish_site_alias.patch"
;projects[varnish][patch][] = "http://cgit.drupalcode.org/varnish/patch/?id=75cb3194ce89cc48b162c49906423884b27c950c"
;projcets[varnish][patch][] = "http://cgit.drupalcode.org/varnish/patch/?id=211afb26cd1d2a93f15007582e3c466fa951c06a"
projects[view_unpublished] = "1.2"
projects[views_accordion] = "1.6"
projects[views_bulk_operations] = "3.5"
projects[views_data_export] = "3.2"
projects[views_field_view] = "1.2"
projects[views_menu_children_filter] = "1.0-rc3"
projects[views_rss] = "2.0-rc4"
projects[webform] = "4.19"
projects[workbench] = "1.2"
projects[workbench_access] = "1.6"
projects[workbench_media] = "1.1"
projects[workbench_moderation][type] = "module"
projects[workbench_moderation][download][type] = "file"
projects[workbench_moderation][download][url] = "https://github.com/JeebsUK/drupal-workbench-moderation/archive/1.4.tar.gz"
projects[workbench_moderation][subdir] = "contrib"
projects[xmlsitemap] = "2.6"


; features

projects[body_field_definition][version] = "1.0"
projects[body_field_definition][patch][] = "http://www.drupal.org/files/issues/foreign-keys-2454593-1.patch"
projects[body_field_definition][subdir] = "features"

projects[cam_access_handling][type] = "module"
projects[cam_access_handling][download][type] = "file"
projects[cam_access_handling][download][url] = "https://github.com/misd-service-development/drupal-feature-access-handling/archive/7.x-1.0.tar.gz"
projects[cam_access_handling][subdir] = "features"


projects[cambridge_events][type] = "module"
projects[cambridge_events][version] = "2.0"
projects[cambridge_events][download][type] = "file"
projects[cambridge_events][download][url] = "https://github.com/misd-service-development/drupal-feature-events/archive/7.x-2.0.tar.gz"
projects[cambridge_events][subdir] = "features"

projects[cambridge_jobs][type] = "module"
projects[cambridge_jobs][download][type] = "file"
projects[cambridge_jobs][download][url] = "https://github.com/misd-service-development/drupal-feature-jobs/archive/7.x-1.0.tar.gz"
projects[cambridge_jobs][subdir] = "features"

projects[cambridge_news][type] = "module"
projects[cambridge_news][download][type] = "file"
projects[cambridge_news][download][url] = "https://github.com/misd-service-development/drupal-feature-news/archive/7.x-2.2.tar.gz"
projects[cambridge_news][subdir] = "features"

projects[cambridge_related_links][type] = "module"
projects[cambridge_related_links][download][type] = "file"
projects[cambridge_related_links][download][url] = "https://github.com/misd-service-development/drupal-feature-related-links/archive/7.x-1.2.tar.gz"
projects[cambridge_related_links][subdir] = "features"

projects[cambridge_questions_and_answers][type] = "module"
projects[cambridge_questions_and_answers][download][type] = "file"
projects[cambridge_questions_and_answers][download][url] = "https://github.com/misd-service-development/drupal-feature-questions-and-answers/archive/7.x-1.3.tar.gz"
projects[cambridge_questions_and_answers][subdir] = "features"

projects[webform_date_format][type] = "module"
projects[webform_date_format][version] = "1.0"
projects[webform_date_format][download][type] = "file"
projects[webform_date_format][download][url] = "https://github.com/misd-service-development/drupal-feature-webform-date-format/archive/7.x-1.0.tar.gz"
projects[webform_date_format][subdir] = "features"
