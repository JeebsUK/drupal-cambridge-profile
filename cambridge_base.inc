<?php

/**
 * @file
 * Base functions for the University of Cambridge installation profiles.
 */

/**
 * Perform actions to set up the site for the profiles.
 */
function cambridge_base_install() {
  // Add text formats.

  $filtered_html_format = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'weight' => 0,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // HTML filter.
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  $filtered_html_format = (object) $filtered_html_format;
  filter_format_save($filtered_html_format);

  $full_html_format = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'weight' => 1,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  $full_html_format = (object) $full_html_format;
  filter_format_save($full_html_format);

  // Add image styles

  $carousel = image_style_save(array('name' => 'carousel', 'label' => 'Carousel'));

  image_effect_save(
    array(
      'name' => 'image_scale',
      'data' => array(
        'width' => 885,
        'height' => NULL,
        'upscale' => TRUE,
      ),
      'isid' => $carousel['isid'],
      'weight' => 1,
    )
  );

  image_effect_save(
    array(
      'name' => 'image_crop',
      'data' => array(
        'width' => 885,
        'height' => 432,
        'anchor' => 'center-center',
      ),
      'isid' => $carousel['isid'],
      'weight' => 2,
    )
  );

  $leading = image_style_save(array('name' => 'leading', 'label' => 'Leading'));

  image_effect_save(
    array(
      'name' => 'image_scale',
      'data' => array(
        'width' => 590,
        'height' => NULL,
        'upscale' => TRUE,
      ),
      'isid' => $leading['isid'],
      'weight' => 1,
    )
  );

  image_effect_save(
    array(
      'name' => 'image_crop',
      'data' => array(
        'width' => 590,
        'height' => 288,
        'anchor' => 'center-center',
      ),
      'isid' => $leading['isid'],
      'weight' => 2,
    )
  );

  $inline = image_style_save(array('name' => 'inline', 'label' => 'Inline/teaser'));

  image_effect_save(
    array(
      'name' => 'image_scale',
      'data' => array(
        'width' => 250,
        'height' => NULL,
        'upscale' => TRUE,
      ),
      'isid' => $inline['isid'],
      'weight' => 1,
    )
  );

  image_effect_save(
    array(
      'name' => 'image_crop',
      'data' => array(
        'width' => 250,
        'height' => 250,
        'anchor' => 'center-center',
      ),
      'isid' => $inline['isid'],
      'weight' => 2,
    )
  );

  // Add content types.

  $types = array(
    array(
      'type' => 'page',
      'name' => st('Basic Page'),
      'base' => 'node_content',
      'description' => st("Use <em>basic pages</em> for your static content, such as an 'About us' page."),
      'custom' => 1,
      'modified' => 1,
      'locked' => 0,
      'has_body' => 1,
    ),
    array(
      'type' => 'carousel_item',
      'name' => st('Carousel Item'),
      'base' => 'node_content',
      'description' => st("Use <em>carousel item</em> to promote key messages on section pages."),
      'custom' => 1,
      'modified' => 1,
      'locked' => 0,
      'has_body' => 0,
      'title_label' => 'Administrative title',
    ),
  );

  foreach ($types as $type) {
    $type = node_type_set_defaults($type);
    node_type_save($type);
    if ($type->has_body) {
      node_add_body_field($type);
    }

    // Not promoted to front page.
    variable_set('node_options_' . $type->type, array('status'));

    // Don't display date and author information.
    variable_set('node_submitted_' . $type->type, FALSE);
  }

  $fields = array(
    'field_leading_image' => array(
      'field_name' => 'field_leading_image',
      'label' => st('Leading image'),
      'cardinality' => 1,
      'type' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
    ),
    'field_related_links' => array(
      'field_name' => 'field_related_links',
      'label' => st('Related links'),
      'cardinality' => -1,
      'type' => 'link_field',
    ),
    'field_carousel_image' => array(
      'field_name' => 'field_carousel_image',
      'label' => st('Carousel image'),
      'cardinality' => 1,
      'type' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
    ),
    'field_carousel_caption' => array(
      'field_name' => 'field_carousel_caption',
      'label' => st('Carousel caption'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
    ),
    'field_carousel_link' => array(
      'field_name' => 'field_carousel_link',
      'label' => st('Carousel link'),
      'cardinality' => 1,
      'type' => 'link_field',
    ),
  );

  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instances = array(
    'field_leading_image' => array(
      'entity_type' => 'node',
      'bundle' => 'page',
      'field_name' => 'field_leading_image',
      'label' => st('Leading image'),
      'cardinality' => 1,
      'type' => 'field_leading_image',
      'settings' => array(
        'alt_field' => 1,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '590x288',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'leading', 'image_link' => ''),
          'weight' => -1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'inline', 'image_link' => 'content'),
          'weight' => -1,
        ),
      ),
    ),
    'field_related_links' => array(
      'entity_type' => 'node',
      'bundle' => 'page',
      'field_name' => 'field_related_links',
      'label' => st('Related links'),
      'cardinality' => -1,
      'type' => 'field_related_links',
      'settings' => array(
        'title' => 'required',
      ),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'field_carousel_image' => array(
      'entity_type' => 'node',
      'bundle' => 'carousel_item',
      'field_name' => 'field_carousel_image',
      'label' => st('Image'),
      'required' => 1,
      'cardinality' => 1,
      'type' => 'field_carousel_image',
      'settings' => array(
        'alt_field' => 1,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '885x432',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'carousel', 'image_link' => ''),
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'inline', 'image_link' => 'content'),
          'weight' => 0,
        ),
      ),
    ),
    'field_carousel_caption' => array(
      'entity_type' => 'node',
      'bundle' => 'carousel_item',
      'field_name' => 'field_carousel_caption',
      'label' => st('Caption'),
      'description' => st('The text to show with the image. If blank, the administrative title will be used.'),
      'required' => 0,
      'cardinality' => 1,
      'type' => 'field_carousel_caption',
      'settings' => array(
        'size' => 60,
        'text_processing' => 0,
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_plain',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'text_plain',
          'weight' => 1,
        ),
      ),
    ),
    'field_carousel_link' => array(
      'entity_type' => 'node',
      'bundle' => 'carousel_item',
      'field_name' => 'field_carousel_link',
      'label' => st('Link'),
      'required' => 1,
      'cardinality' => 1,
      'type' => 'field_carousel_caption',
      'settings' => array(
        'title' => 'none',
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'link_url',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'link_url',
          'weight' => 2,
        ),
      ),
    ),
  );

  foreach ($instances as $instance) {
    field_create_instance($instance);
  }

  // Basic Pages can have a main-menu item.
  variable_set('menu_options_page', array('main-menu'));

  // Carousel Items shouldn't be on a menu.
  variable_set('menu_options_carousel_item', array());

  // Allow visitor account creation with administrative approval.
  variable_set('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL);

  // Enable the default and admin theme.
  $enable = array(
    'theme_default' => 'cambridge_theme',
    'admin_theme' => 'seven',
  );
  theme_enable($enable);

  foreach ($enable as $var => $theme) {
    if (!is_numeric($var)) {
      variable_set($var, $theme);
    }
  }

  theme_disable(array('bartik'));

  // Use the admin theme for creating/editing nodes
  variable_set('node_admin_theme', 1);

  // Insert the page_title block required by the theme
  db_insert('block_custom')
    ->fields(
      array(
        'body' => "<h1>\n<?php\nprint drupal_get_title();\n?>\n</h1>",
        'info' => 'Page title',
        'format' => 'php_code',
      )
    )
    ->execute();

  // Insert the horizontal menu block required by the theme
  variable_set("menu_block_1_title_link", 0);
  variable_set("menu_block_1_admin_title", 'Horizontal menu');
  variable_set("menu_block_1_parent", 'main-menu:0');
  variable_set("menu_block_1_level", 1);
  variable_set("menu_block_1_follow", 0);
  variable_set("menu_block_1_depth", 0);
  variable_set("menu_block_1_expanded", 1);
  variable_set("menu_block_1_sort", 0);

  // Insert the vertical menu block required by the theme
  variable_set("menu_block_2_title_link", 0);
  variable_set("menu_block_2_admin_title", 'Vertical menu');
  variable_set("menu_block_2_parent", 'main-menu:0');
  variable_set("menu_block_2_level", 1);
  variable_set("menu_block_2_follow", 1);
  variable_set("menu_block_2_depth", 0);
  variable_set("menu_block_2_expanded", 0);
  variable_set("menu_block_2_sort", 1);

  variable_set('menu_block_ids', array(1, 2));

  // Hide Drupal's standard menu blocks
  variable_set('menu_block_suppress_core', 1);

  $theme = 'cambridge_theme';

  $blocks = array(
    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'title' => '',
      'cache' => DRUPAL_NO_CACHE,
    ),
    array(
      'module' => 'user',
      'delta' => 'login',
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 10,
      'region' => 'sidebar',
      'pages' => '',
      'title' => '',
      'cache' => DRUPAL_NO_CACHE,
    ),
    array(
      'module' => 'block',
      'delta' => 1,
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 0,
      'region' => 'page_title',
      'pages' => '<front>',
      'title' => '',
      'cache' => DRUPAL_NO_CACHE,
    ),
    array(
      'module' => 'menu_block',
      'delta' => 1,
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 0,
      'region' => 'horizontal_navigation',
      'pages' => '',
      'title' => '<none>',
      'cache' => DRUPAL_NO_CACHE,
    ),
    array(
      'module' => 'menu_block',
      'delta' => 2,
      'theme' => $theme,
      'status' => TRUE,
      'weight' => 0,
      'region' => 'left_navigation',
      'pages' => "<front>\nadmin/\nadmin/*\ncarousel/*\nuser\nuser/*",
      'title' => '<none>',
      'cache' => DRUPAL_NO_CACHE,
    ),
  );

  $query = db_insert('block')
    ->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'pages', 'title', 'cache'));

  foreach ($blocks as $block) {
    $query->values($block);
  }

  $query->execute();

  // Insert default pre-defined RDF mapping into the database.
  $rdf_mappings = array(
    array(
      'type' => 'node',
      'bundle' => 'page',
      'mapping' => array(
        'rdftype' => array('foaf:Document'),
      ),
    ),
  );
  foreach ($rdf_mappings as $rdf_mapping) {
    rdf_mapping_save($rdf_mapping);
  }

  // Enable default permissions for system roles.
  $filtered_html_permission = filter_permission_name($filtered_html_format);
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access content', $filtered_html_permission));
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access content', $filtered_html_permission));

  // Create a default role for site administrators, with all available permissions assigned.
  $admin_role = new stdClass();
  $admin_role->name = 'administrator';
  $admin_role->weight = 2;
  user_role_save($admin_role);
  user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
  // Set this as the administrator role.
  variable_set('user_admin_role', $admin_role->rid);

  // Assign user 1 the "administrator" role.
  db_insert('users_roles')
    ->fields(array('uid' => 1, 'rid' => $admin_role->rid))
    ->execute();

  // Reset anonymous and authenticated user permissions.

  user_role_grant_permissions(1, array('access content', 'search content'));
  user_role_grant_permissions(2, array('access content', 'search content'));

  // Create a Home link in the main menu.
  $item = array(
    'link_title' => st('Home'),
    'link_path' => '<front>',
    'menu_name' => 'main-menu',
    'weight' => -100,
  );
  menu_link_save($item);

  // Update the menu router information.
  menu_rebuild();

  // Create a carousel view and make it visible on the front page.

  $view = new view();
  $view->name = 'carousel';
  $view->description = 'Used to promote key messages on section pages.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Carousel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'campl-slide campl-column12';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'campl-unstyled-list campl-slides';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_link']['id'] = 'field_carousel_link';
  $handler->display->display_options['fields']['field_carousel_link']['table'] = 'field_data_field_carousel_link';
  $handler->display->display_options['fields']['field_carousel_link']['field'] = 'field_carousel_link';
  $handler->display->display_options['fields']['field_carousel_link']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_carousel_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_carousel_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_carousel_image']['id'] = 'field_carousel_image';
  $handler->display->display_options['fields']['field_carousel_image']['table'] = 'field_data_field_carousel_image';
  $handler->display->display_options['fields']['field_carousel_image']['field'] = 'field_carousel_image';
  $handler->display->display_options['fields']['field_carousel_image']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_carousel_image']['alter']['path'] = '[field_carousel_link]';
  $handler->display->display_options['fields']['field_carousel_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_carousel_image']['element_class'] = 'image-container';
  $handler->display->display_options['fields']['field_carousel_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_carousel_image']['settings'] = array(
    'image_style' => 'carousel',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_carousel_caption']['id'] = 'field_carousel_caption';
  $handler->display->display_options['fields']['field_carousel_caption']['table'] = 'field_data_field_carousel_caption';
  $handler->display->display_options['fields']['field_carousel_caption']['field'] = 'field_carousel_caption';
  $handler->display->display_options['fields']['field_carousel_caption']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_caption']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_carousel_caption']['alter']['text'] = '<span class="campl-slide-caption-txt">[field_carousel_caption]</span>';
  $handler->display->display_options['fields']['field_carousel_caption']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_carousel_caption']['alter']['path'] = '[field_carousel_link]';
  $handler->display->display_options['fields']['field_carousel_caption']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_carousel_caption']['element_class'] = 'campl-slide-caption';
  $handler->display->display_options['fields']['field_carousel_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_caption']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_caption']['empty'] = '<span class="campl-slide-caption-txt">[title]</span>';
  $handler->display->display_options['fields']['field_carousel_caption']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array('carousel_item' => 'carousel_item',);

  $view->new_display('block', 'Block', 'block');

  $view->update();

  $view->init_display();

  $view->save();

  db_insert('block')
    ->fields(
      array(
        'module' => 'views',
        'delta' => 'carousel-block',
        'theme' => 'cambridge_theme',
        'status' => TRUE,
        'weight' => 0,
        'region' => 'carousel',
        'custom' => BLOCK_CUSTOM_FIXED,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'pages' => '<front>',
        'title' => '<none>',
        'cache' => DRUPAL_NO_CACHE,
      )
    )
    ->execute();

  // Create a view for the related links field and make it visible in the sidebar.

  $view = new view();
  $view->name = 'related_links';
  $view->description = 'Display a list of related links for a node.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related links';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'campl-unstyled-list campl-related-links';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['fields']['field_related_links']['id'] = 'field_related_links';
  $handler->display->display_options['fields']['field_related_links']['table'] = 'field_data_field_related_links';
  $handler->display->display_options['fields']['field_related_links']['field'] = 'field_related_links';
  $handler->display->display_options['fields']['field_related_links']['label'] = '';
  $handler->display->display_options['fields']['field_related_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_links']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_related_links']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_related_links']['delta_offset'] = '0';
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'page' => 'page',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'empty';
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['field_related_links_url']['id'] = 'field_related_links_url';
  $handler->display->display_options['filters']['field_related_links_url']['table'] = 'field_data_field_related_links';
  $handler->display->display_options['filters']['field_related_links_url']['field'] = 'field_related_links_url';
  $handler->display->display_options['filters']['field_related_links_url']['operator'] = 'not empty';

  $view->new_display('block', 'Block', 'block');

  $view->update();

  $view->init_display();

  $view->save();

  db_insert('block')
    ->fields(
      array(
        'module' => 'views',
        'delta' => 'related_links-block',
        'theme' => 'cambridge_theme',
        'status' => TRUE,
        'weight' => 1,
        'region' => 'sidebar',
        'custom' => BLOCK_CUSTOM_FIXED,
        'visibility' => BLOCK_VISIBILITY_NOTLISTED,
        'pages' => '',
        'title' => '',
        'cache' => DRUPAL_NO_CACHE,
      )
    )
    ->execute();
}

/**
 * Allows the profile to alter the site configuration form.
 */
function cambridge_base_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the default country with United Kingdom.
  $form['server_settings']['site_default_country']['#default_value'] = 'GB';

  // Make sure the timezone is Europe/London.
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/London';
  unset($form['server_settings']['date_default_timezone']['#attributes']['class']);

  // Only check for updates, no need for email notifications.
  $form['update_notifications']['update_status_module']['#default_value'] = array(1);
}