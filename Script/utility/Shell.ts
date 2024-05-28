namespace Twinning.Script.Shell {

	// ------------------------------------------------

	export function callback(
		argument: Array<string>,
	): Array<string> {
		return KernelX.Miscellaneous.callback(argument);
	}

	// ------------------------------------------------

	export const name = String(callback(['name'])[0]);

	export const is_basic = name === 'basic';

	export const is_assistant = name === 'assistant' || name === 'assistant.plus';

	// ------------------------------------------------

	export const version = String(callback(['version'])[0]);

	// ------------------------------------------------

	export function basic_output_text(
		text: string,
	): {} {
		let result = callback(['output_text', text]);
		return {};
	}

	export function basic_input_text(
	): { text: string; } {
		let result = callback(['input_text']);
		return { text: result[0] };
	}

	export function basic_pick_path(
		type: 'open_file' | 'open_directory' | 'save_file',
	): { selection: string; } {
		if (KernelX.is_android || KernelX.is_iphone) {
			// unavailable, silently fail
			return { selection: '' };
		}
		let result = callback(['pick_path', type]);
		return { selection: result[0] };
	}

	export function basic_push_notification(
		title: string,
		description: string,
	): {} {
		if (KernelX.is_android || KernelX.is_iphone) {
			// unavailable, silently fail
			return {};
		}
		let result = callback(['push_notification', title, description]);
		return {};
	}

	// ------------------------------------------------

	export function assistant_send_message(
		type: 'verbosity' | 'information' | 'warning' | 'error' | 'success' | 'input',
		title: string,
		description: Array<string>,
	): {} {
		let result = callback(['send_message', type, title, ...description]);
		return {};
	}

	export function assistant_receive_submission(
		type: 'pause' | 'boolean' | 'integer' | 'floater' | 'size' | 'string' | 'path' | 'enumeration',
		option: Array<string>,
	): { value: string; } {
		let result = callback(['receive_submission', type, ...option]);
		return { value: result[0] };
	}

	export function assistant_pick_path(
		type: 'open_file' | 'open_directory' | 'save_file',
	): { selection: string; } {
		let result = callback(['pick_path', type]);
		return { selection: result[0] };
	}

	export function assistant_push_notification(
		title: string,
		description: string,
	): {} {
		let result = callback(['push_notification', title, description]);
		return {};
	}

	// ------------------------------------------------

}