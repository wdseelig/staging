<?php
	function contactselect_views_query_alter(&$view, &$query) {
			watchdog('contactselectqaueryalter','Made it into the query alter routine');
//				kpr($view);
//				kpr($query);
//				if ($view->name == 'ContactsWithTags'){
//			$view->display_handler->handlers->filter->field_tagswithhs_tid->value = array();
//			$view->display_handler->handlers->filter->field_tagswithhs_tid->value[] = '20';
//				kpr($view);
//				kpr($query);
		}

		